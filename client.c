#include "client.h"


char** getInput(char* input, char** buffer){
	char* delim = " " ;
	int len = strlen(input) ;
    char *token = strtok(input, delim);
    int index = 0;

    while (token != NULL) {
    
        buffer[index++] = token;
        token = strtok(NULL, delim);	// Get to next parameter
    
    }
    
    buffer[index] = NULL ;	// To indicate the end of the parameters for execvp

    if(index != 2){

    	return NULL ;

    }

    return buffer ;
}