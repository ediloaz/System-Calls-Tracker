// main file
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

#define TOTAL_SYSCALLS 548

int main(int argc, char *argv[]){
	char syscalls[TOTAL_SYSCALLS][120];
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t length;
 
	stream = fopen("/usr/include/x86_64-linux-gnu/asm/unistd_64.h", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);
	
	int cont = 0;
 
	while ((length = getline(&line, &len, stream)) != -1) 
	{
		if((cont++ > 2) && (line[1] == 'd'))
		{
			char newline[length - 13];
			for (int i = 0; i < length - 13; i++)
			{
				newline[i] = line[i + 13];
			}
			char *name = strtok(newline, " ");
			int index = atoi(strtok(NULL, " "));
			strcpy(syscalls[index], name);
		}
	}
 
	free(line);
	fclose(stream);

    int option = 0; //puede ser 0 para nada, 1 para v o 2 para V
    char* childProgramName;
    char* childProgramCommand;
    int paramIndex = 1;
    //LEE PARÁMETROS DE RASTREADOR Y NOMBRE DE PROGRAMA HIJO
    while(paramIndex < argc)
    {
    	char* param = argv[paramIndex];
    	paramIndex++;
    	
    	//Verifica si hay parámetros de rastreador
    	if(param[0] == '-'){
    	    switch(param[1]){
    	    	case 'v':
    	    	option = (option == 0? 1 : option);
    	    	printf("Seleccionó opción v\n");
    	    	break;
    	    case 'V':
    	    	option = 2;
    	    	printf("Seleccionó opción V\n");
    	    	break;
    	    default:
    	    	printf("Error: Parámetro no reconocido\n");
    	    	return 1;
    	    }
    	}
    	//Obtiene nombre de programa
    	else{
    	    childProgramName = param;
    	    printf("El nombre del programa por ejecutar es: %s\n",param);
    	    break;
    	}    	
    	
    }
    printf("Se ejecutara programa en modo: %d\n",option);

    
    long orig_eax;
    struct user_regs_struct regs;
    int status; 
    int in_call = 0;
    
    int contador_syscalls[TOTAL_SYSCALLS] = {0};
    
    pid_t pid = fork();
    if(pid == -1){
    	perror("Error al hacer fork");
    	exit(1);
    }
    //Proceso hijo que se rastrea
    if(pid == 0){
    	//Permite que el proceso sea rastreado
    	ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    	//Ejecuta programa hijo
    	execvp(childProgramName, argv + paramIndex - 1);    	
    }else{
    
    //Proceso padre
    	wait(&status);
    	//1407: exit
    	while(status == 1407){    	    
    	
    	    orig_eax = ptrace(PTRACE_GETREGS, pid, NULL, &regs);
    	
    	    if(orig_eax < 0){
    	        printf("Error\n");
    	        exit(EXIT_FAILURE);
    	    }
    	    
    	    if(!in_call){
    	    	printf("Programa realizó system call %s(%lld) llamado con %lld, %lld, %lld \n", syscalls[regs.orig_rax], regs.orig_rax, regs.rbx, regs.rcx, regs.rdx);
    	    	
    	    	contador_syscalls[regs.orig_rax] ++;
    	    	
    	    	if(option == 2){
    	    	    //Pausar la ejecución después de imprimir syscall
    	    	    getchar();
    	    	}
    	    	in_call = 1;    	    	
    	    }else{
    	    	in_call = 0;
    	    }
    	    ptrace(PTRACE_SYSCALL, pid, NULL, NULL); //Continúa ejecución de programa
    	    wait(&status);
    	}
    	
    	
    	//IMPRIMIT TABLA RESUMEN
    	printf("\nID	║ CONT	║ NOMBRE	\n");
    	printf("══════════════════════════ \n");
    	for(int i=0; i < TOTAL_SYSCALLS ; i++){
    	    if(contador_syscalls[i] > 0){
    	         printf("%d	║ %d	║ %s\n", i, contador_syscalls[i], syscalls[contador_syscalls[i]]);
    	    }  	
    	}

    }   
        
    return 0;
}
