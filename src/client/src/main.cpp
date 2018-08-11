
#include <Client.hpp>

int			main()
{
	Client		c;

	c.send();
	sleep(3);
	c.send();
	sleep(3);
	c.send();
	sleep(3);
	c.send();
	sleep(3);
	c.send();
	sleep(3);

	// while (true)
	// 	try	{
	// 		c.send();
	// 	}
	// 	catch( const std::exception &e ) {
	// 		std::cerr << e.what() << std::endl;
	// 	}

	return 0;
}
