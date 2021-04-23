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


int main(int argc, char *argv[]){
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
    
    //LEE PARÁMETROS DE PROGRAMA HIJO
    int sizeChildParams = 0;
    for(int i=paramIndex; i < argc; i++){
    	char* param = argv[i];
    	
    	sizeChildParams += strlen(param) + 1;
    }
    childProgramCommand = malloc (strlen(childProgramName) + sizeChildParams + 1);
    if(childProgramCommand == NULL){
    	printf("Error al hacer malloc");
    	return 1;
    }
    strcpy(childProgramCommand, childProgramName);
    for(int i=paramIndex; i < argc; i++){
    	char* param = argv[i];
    	strcat(childProgramCommand, " ");
	strcat(childProgramCommand, param);
    }
	
    
    long orig_eax;
    struct user_regs_struct regs;
    int status; 
    int in_call = 0;
    //int inputParaContinuar;
    
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
    	        //fprintf(stderr, "%s\n", explain_ptrace(PTRACE_PEEKUSER, pid, 4*ORIG_RAX, NULL));
    	        exit(EXIT_FAILURE);
    	    }
    	    
    	    if(!in_call){
    	    	printf("Programa realizó system call %lld llamado con %lld, %lld, %lld \n", regs.orig_rax, regs.rbx, regs.rcx, regs.rdx);
    	    	
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
    	
    	
    	
    	
    }   
    
    free(childProgramCommand);
    
    return 0;
}
