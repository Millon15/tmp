
#include <Server.hpp>

Server::Server( void )
{
	int						opt = 1;

	// Creating socket file descriptor
	if ( (_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0 ) {
		perror("Socket creation failed"); exit(1);
	}

	// Forcefully attaching socket to the port PORT
	if ( setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) )
	{
		perror("setsockopt() failed"); close(_sock); exit(2);
	}
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(PORT);
	if (bind(_sock, (struct sockaddr *)&_address, sizeof(_address)) < 0 ) {
		perror("Bind failed"); close(_sock); exit(3);
	}
	if (listen(_sock, LISTEN_BACKLOG) < 0) {
		perror("Bad listen"); close(_sock); exit(4);
	}
}
Server::~Server( void )
{
	close(_sock);
}

void		Server::recieve( void )
{
	int			next, ret;
	pid_t		forfork;
	// int			addrlen = sizeof(_address);
	char		answ[ANSW_LEN] = {48};
	char		buffer[RAND_STR_SIZE];

	while ( true ) {
		if ( (next = accept(_sock, NULL, NULL)) < 0 ) {
			perror("Bad accept"); close(_sock); exit(5);
		}

		if ( (forfork = fork()) < 0 ) {
			perror("Bad fork"); close(_sock); close(next); exit(6);
		}
		else if ( forfork == 0 ) {
			if ( close(_sock) < 0 ) {
				perror("Bad close"); close(next); exit(7);
			}

			while ( true ) {
				if ( (ret = recv(next, buffer, RAND_STR_SIZE + 1, 0)) < 0 ) {
					break ;
				}
				std::cout << buffer[RAND_STR_SIZE - 1] << " " << ret << std::endl;
				if ( ::send(next, answ, ANSW_LEN + 1, MSG_OOB) < 0 ) {
					perror("Bad send"); close(next); exit(8);
				}
			}

			if ( close(next) < 0 ) {
				perror("Bad close"); exit(9);
			}
			exit(0);
		}
		if ( close(next) < 0 ) {
			perror("Bad close"); exit(10);
		}
	}
}
