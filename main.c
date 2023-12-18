#include "display.h"


int main(int argc, char* argv[]){

	if(argc != MAX_PARAM_NUMBER){		// Check for correct usage
		usage() ;
		return EXIT_FAILURE ;
	}

	char* hostname = argv[1] ;
	printInput(hostname) ;

}