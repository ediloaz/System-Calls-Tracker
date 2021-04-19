// main file
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int opt;
    int option = 0; //puede ser 0 para nada, 1 para v o 2 para V
    
    int paramIndex = 1;
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
    	    printf("El nombre del programa por ejecutar es: %s\n",param);
    	    break;
    	}    	
    	
    }
    printf("Se ejecutara programa en modo: %d\n",option);
    printf("Los parámetros de prog son:\n");
    while(paramIndex < argc){
    	char* param = argv[paramIndex];
    	paramIndex++;
    	printf("%s\n",param);
    }
    return 0;
}
