
#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <sys/types.h>
# include <sys/uio.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <string.h>

# define RAND_STR_SIZE	1024
# define PORT 8080


class Client {

private:
	// std::string		&getRandStr( void );

	// int		sock;

public:
	Client( void );
	~Client( void );

	// std::string		&send( void );
	void			mai( void );
};

#endif
