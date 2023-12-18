#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* Macros and defines */

#define MAX_PARAM_NUMBER 2
#define USAGE "Wrong parameters, usage is: ./tftp <server>"


#define INPUT_ERROR "NULL parameter given."
#define WRITTING_OUT_ERROR "Error while writting to STDOUT_FILENO"
#define WRITTING_ERR_ERROR "Error while writting to STDERR_FILENO"


/* Function declarations */

void usage(void) ;
void printInput(char*) ;