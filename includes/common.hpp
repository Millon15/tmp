
#ifndef COMMON_HPP
# define COMMON_HPP

# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/uio.h>
# include <arpa/inet.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include <string>
# include <iostream>

# define PORT			8080
# define RAND_STR_SIZE	1024
# define LISTEN_BACKLOG	20
# define ANSW_LEN		10

#endif
