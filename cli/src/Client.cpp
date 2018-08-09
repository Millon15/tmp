
#include <Client.hpp>

Client::Client( void )
{
	return ;
}
Client::~Client( void )
{
	return ;
}

// std::string			Client::send( void )
// {
// 	std::string		str;

// 	// SOCKET << getRandStr();

// 	return str;
// }

// std::string			&Client::getRandStr( void )
// {
// 	std::string			rstr(RAND_STR_SIZE, '\0');
// 	static const char	alphanum[] =
// 	"0123456789"
// 	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// 	"abcdefghijklmnopqrstuvwxyz";

// 	srand(time(NULL));
// 	for ( int i = 0; i < RAND_STR_SIZE; i++ )
// 		rstr[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

// 	return rstr;
// }

void				Client::mai( void )
{
	struct sockaddr_in		address;
	struct sockaddr_in		serv_addr;
	int						valread;
	int						sock = 0;
	char					hello[] = "CLIENT";
	char					buffer[1024] = {0};

	// Creating socket file descriptor
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Socket failed"); exit(1);
	}

	bzero(&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		perror("Bad ip address"); exit(2);
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("Bad connect"); exit(2);
	}
	send(sock , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");
	valread = read( sock , buffer, 1024);
	printf("%s\n",buffer );
}
