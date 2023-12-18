#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>


/* Macros and defines */

#define MAX_PARAM_NUMBER 2
#define MAX_STRING_SIZE 1024
#define USAGE "Wrong parameters, usage is: ./tftp <server>\r\n"
#define NEWLINE "--------------------\r\n"
#define FAMILY_NOT_SUPPORTED "Address family not supported\r\n"
#define CONNECTION_OK "Connection successful\r\n"


#define INPUT_ERROR "NULL parameter given."
#define WRITTING_OUT_ERROR "Error while writting to STDOUT_FILENO"
#define WRITTING_ERR_ERROR "Error while writting to STDERR_FILENO"
#define ADDRINFO_ERROR "Error while getting address infos"
#define SOCKET_ERROR "Error while creating the socket"
#define CONNECTION_ERROR "Error while connecting to the server"


/* Function declarations */

void usage(void) ;
void printAddrInfo(struct addrinfo*) ;