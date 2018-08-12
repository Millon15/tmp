
#include <Client.hpp>

int			main()
{
	const int	clients_count = 3;
	Client		c[clients_count];
	int			i;

	for ( i = 0; i < clients_count; i++ ) {
		c[i].send(); sleep(1);
	}

	for ( i = 0; i < clients_count; i++ ) {
		c[i].send(); sleep(1);
	}


	return 0;
}
