// main file
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	    
    
    free(childProgramCommand);
    
    return 0;
}
