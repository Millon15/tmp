
#include <Server.hpp>

Server::Server( void )
{
	return ;
}
Server::~Server( void )
{
	return ;
}

void		Server::mai( void )
{
	struct sockaddr_in		address;
	int						server_fd, new_socket, valread;
	int						opt = 1;
	int						addrlen = sizeof(address);
	char					hello[] = "SERVER";
	char					buffer[1024] = {0};

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("Socket failed"); exit(1);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt"); exit(2);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("Bind failed"); exit(3);
	}
	if (listen(server_fd, 3) < 0) {
		perror("Bad listen"); exit(4);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
		perror("Bad accept"); exit(5);
	}
	valread = read( new_socket , buffer, 1024 );
	printf("%s\n", buffer );
	send( new_socket , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");
}
