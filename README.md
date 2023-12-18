# TFTP

This is the repository of the TFTP client made in lab sessions of IT major.


## Question 1

	The first question needs us to get the parameters given by the user.
	Due to how we want to implement the client, we only focus on the server (called "hostname") in our code we
	use would had been the same if we also took care of the file with just some quick modifications (mostly
	the macros).

	The only errors currently handle are a wrong usage of the function or error writting in the different
	output (because there is nothing else that could go wrong yet).

## Question 2

	The second question needs us to get the information of the server put in argument.
	This is down with the use of getaddrinfo. I create another function to print the data that getaddrinfo has
	return.

	The errors handle stay the same with the addition of an error while getting the information with getaddrinfo.

## Question 3

	The third question needs us to create a socket and connect to the server put in argument.
	To do so, we use the socket function and connect function with the correct argument:
		- INET family
		- DGRAM socktype
		- UDP protocol

	Errors now handle connection and socket error.