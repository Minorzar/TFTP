#include "display.h"


int main(int argc, char* argv[]){
	struct addrinfo hints ;
    struct addrinfo* serverInfo ;
    int outputCode ;

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


    close(clientSocket);

    freeaddrinfo(serverInfo) ;

    return EXIT_SUCCESS ;

}