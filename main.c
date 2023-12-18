#include "display.h"
#include "client.h"
#include "gettftp.h"


int main(int argc, char* argv[]){
	struct addrinfo hints ;
    struct addrinfo* serverInfo ;
    int outputCode ;
    char userInput[MAX_INPUT_SIZE];
	ssize_t byteRead;
	char* inputBuffer[MAX_INPUT_SIZE] ;

	if(argc != MAX_PARAM_NUMBER){		// Check for correct usage
		usage() ;
		return EXIT_FAILURE ;
	}

	char* hostname = argv[1] ;


    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    outputCode = getaddrinfo(hostname, NULL, &hints, &serverInfo);		// get address matching selection criteria define in hints		
    if (outputCode != 0) {
        
        perror(ADDRINFO_ERROR) ;
        exit(EXIT_FAILURE) ;
    
    }

    printAddrInfo(serverInfo) ;

     int clientSocket = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
    if (clientSocket == -1) {
        perror(SOCKET_ERROR);
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, serverInfo->ai_addr, serverInfo->ai_addrlen) == -1) {
        perror(CONNECTION_ERROR);
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    printf(CONNECTION_OK);

    printPrompt() ;


    while (1) {

    	byteRead = read(STDIN_FILENO, userInput, sizeof(userInput));

        // Reading error
    	if (byteRead < 0) {

       	 writeTo(STDERR_FILENO, READ_ERROR);
        
        }

        // Ctrl + d case
        if (byteRead == 0) {

            return EXIT_SUCCESS;
        
        }

		// No input (just enter)
        if (byteRead == 1) {

       		printPrompt();
        
   		}

		else {
            
            if (byteRead) {

            	// Get rid of \n
    			userInput[byteRead - 1] = '\0';

            }

            // Exit case
            if (strcmp(userInput, EXIT) == 0) {

                return EXIT_SUCCESS;
            
            }

            getInput(userInput, inputBuffer) ;

            if(inputBuffer == NULL){

            	writeTo(STDERR_FILENO, TOO_MANY_PARAMETERS) ;
            	return EXIT_FAILURE ;

            }


            char function[MAX_INPUT_SIZE] ;
            char filename[MAX_INPUT_SIZE] ;

            strcpy(function, inputBuffer[0]) ;
            strcpy(filename, inputBuffer[1]) ;

            FILE* file = fopen(filename, "w");
    		if (file == NULL){
        	
        		perror(FILE_ERROR);
        		exit(EXIT_FAILURE);
    		
    		}

    		if(strcmp(GETTFTP, function) == 0){

    			receiveDataPacket(clientSocket, file);
    			printPrompt() ;

    		}

    	}

    }


    close(clientSocket);

    freeaddrinfo(serverInfo) ;

    return EXIT_SUCCESS ;

}