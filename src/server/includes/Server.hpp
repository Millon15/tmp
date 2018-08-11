
#ifndef SERVER_HPP
# define SERVER_HPP

#include <common.hpp>


class Server {

private:
	struct sockaddr_in		_address;
	int						_sock;

public:
	Server( void );
	~Server( void );

	void		recieve( void );
	// void		mai( void );
};

#endif
