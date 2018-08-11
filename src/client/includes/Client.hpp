
#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <common.hpp>


class Client {

private:
	int		_sock;

	char			*getRandStr( void );

public:
	Client( void );
	~Client( void );

	char			*send( void );
	// void			mai( void );
};

#endif
