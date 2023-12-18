#include "display.h"



/* Writting functions */


void errorWritting(ssize_t value, int output){

	if(value == -1){

		if(output == STDOUT_FILENO){

			perror(WRITTING_OUT_ERROR) ;

		}
		else if(output == STDERR_FILENO){

			perror(WRITTING_ERR_ERROR) ;

		}

		exit(EXIT_FAILURE) ;

	}

}


// Write data to designated output and check for error
void writeTo(int output, char* data){
	ssize_t byteWritten ;

	byteWritten = write(output, data, strlen(data));		
	errorWritting(byteWritten, output) ;

}



/* Client functions */


void usage(){

	writeTo(STDERR_FILENO, USAGE) ;

}


void printAddrInfo(struct addrinfo* ai){
    while (ai != NULL) {

        char addrStr[INET6_ADDRSTRLEN];

        char family[MAX_STRING_SIZE] ;
        char socktype[MAX_STRING_SIZE] ;
        char protocol[MAX_STRING_SIZE] ;
        char flags[MAX_STRING_SIZE] ;
        char canonname[MAX_STRING_SIZE] ;
        char address[MAX_STRING_SIZE] ;
        char addressLength[MAX_STRING_SIZE] ;


        snprintf(family, MAX_STRING_SIZE, "Family: %d\n", ai->ai_family);
        writeTo(STDOUT_FILENO, family) ;

        snprintf(socktype, MAX_STRING_SIZE, "Socktype: %d\n", ai->ai_socktype);
        writeTo(STDOUT_FILENO, socktype) ;

        snprintf(protocol, MAX_STRING_SIZE, "Protocol: %d\n", ai->ai_protocol);
        writeTo(STDOUT_FILENO, protocol) ;

        snprintf(flags, MAX_STRING_SIZE, "Flags : %d\n", ai->ai_flags);
        writeTo(STDOUT_FILENO, flags) ;

        snprintf(canonname, MAX_STRING_SIZE, "Canonname : %s\n", ai->ai_canonname);
        writeTo(STDOUT_FILENO, canonname) ;


        // Check the family (ipv4 or ipv6)
        if (ai->ai_family == AF_INET){														// ipv4
            
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)ai->ai_addr;
            inet_ntop(AF_INET, &(ipv4->sin_addr), addrStr, INET_ADDRSTRLEN);
            
            snprintf(address, MAX_STRING_SIZE, "Address: %s\n", addrStr);					// get the address as an ipv4
            writeTo(STDOUT_FILENO, address) ;

            snprintf(addressLength, MAX_STRING_SIZE, "Address length: %u\n", ipv4->sin_port);
        	writeTo(STDOUT_FILENO, addressLength) ;

        }
        else if (ai->ai_family == AF_INET6){												// ipv6
            
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ai->ai_addr;
            inet_ntop(AF_INET6, &(ipv6->sin6_addr), addrStr, INET6_ADDRSTRLEN);				// get the address as an ipv6
            
            snprintf(address, MAX_STRING_SIZE, "Address: %s\n", addrStr);
            writeTo(STDOUT_FILENO, address) ;

            snprintf(addressLength, MAX_STRING_SIZE, "Address length: %u\n", ipv6->sin6_port);
        	writeTo(STDOUT_FILENO, addressLength) ;

        }
        else{
        
            writeTo(STDOUT_FILENO, FAMILY_NOT_SUPPORTED) ;									// no address found
        
        }

        writeTo(STDOUT_FILENO, NEWLINE) ;


        ai = ai->ai_next;
    
    }

}


void printPrompt(){

	writeTo(STDOUT_FILENO, PROMPT) ;

}
