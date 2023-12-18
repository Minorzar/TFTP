#include "display.h"


void usage(){
	ssize_t byteWritten ;

	byteWritten = write(STDOUT_FILENO, USAGE, sizeof(USAGE)) ;
	
	if(byteWritten == -1){
	
		perror(WRITTING_OUT_ERROR) ;
		exit(EXIT_FAILURE) ;

	}

}


// Will be remove, use to show that user input correct.
void printInput(char* userInput){
	ssize_t byteWritten ;

	if (userInput != NULL){

		byteWritten = write(STDOUT_FILENO, userInput, sizeof(userInput)) ;

		if(byteWritten == -1){
			
			perror(WRITTING_OUT_ERROR) ;
			exit(EXIT_FAILURE) ;

		}

	}
	else{	

		byteWritten = write(STDERR_FILENO, INPUT_ERROR, sizeof(INPUT_ERROR)) ;
	
		if(byteWritten == -1){
			
			perror(WRITTING_ERR_ERROR) ;
			exit(EXIT_FAILURE) ;

		}

	}

}