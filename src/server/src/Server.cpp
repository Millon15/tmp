
#include <Server.hpp>

Server::Server( void )
{
	int						opt = 1;

	// Creating socket file descriptor
	if ((_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("Socket failed"); exit(1);
	}

	// Forcefully attaching socket to the port PORT
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt"); close(_sock); exit(2);
	}
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(PORT);
	if (bind(_sock, (struct sockaddr *)&_address, sizeof(_address)) < 0) {
		perror("Bind failed"); close(_sock); exit(3);
	}
	if (listen(_sock, 3) < 0) {
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
	int			addrlen = sizeof(_address);
	char		answ[ANSW_LEN] = {48};
	char		buffer[RAND_STR_SIZE];

	if ((next = accept(_sock, (struct sockaddr *)&_address, (socklen_t*)&addrlen)) < 0) {
		perror("Bad accept"); close(_sock); exit(5);
	}
	ret = read(next, buffer, RAND_STR_SIZE);
	std::cout << ret << std::endl;
	::send(next, answ, ANSW_LEN, 0);
}
