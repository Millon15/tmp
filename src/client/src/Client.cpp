
#include <Client.hpp>

Client::Client( void )
{
	struct sockaddr_in		serv_addr;

	// Creating socket file descriptor
	if ( (_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
		perror("Socket creation failed"); exit(1);
	}

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if( inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 ) {
		perror("Bad ip address"); close(_sock); exit(2);
	}
	if ( connect(_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ) {
		perror("Bad connect"); close(_sock); exit(2);
	}
}
Client::~Client( void )
{
	close(_sock);
}

char			*Client::send( void )
{
	char		*rstr = getRandStr();
	char		buffer[ANSW_LEN];
	int			ret;

	if ( ::send(_sock, rstr, RAND_STR_SIZE, MSG_OOB) < 0 ) {
		perror("Bad send"); close(_sock); exit(3);
	}
	// read(_sock, buffer, ANSW_LEN);
	ret = recv(_sock, buffer, ANSW_LEN, MSG_WAITALL);
	std::cout << ret << std::endl;

	return rstr;
}

char				*Client::getRandStr( void )
{
	char				*rstr = new char[RAND_STR_SIZE];
	static const char	alphanum[] =
	"0123456789"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));
	for ( int i = 0; i < RAND_STR_SIZE; i++ )
		rstr[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

	return rstr;
}
