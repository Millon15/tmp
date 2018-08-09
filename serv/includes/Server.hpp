
#ifndef SERVER_HPP
# define SERVER_HPP

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080


class Server {

private:
	int		_sock;

public:
	Server( void );
	~Server( void );

	void		mai( void );
};

#endif
