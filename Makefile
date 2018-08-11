# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/08/11 18:48:38 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERV = server
CLI = client

SRC_PATH = src/
SERVER_PATH = $(SRC_PATH)server/
CLIENT_PATH = $(SRC_PATH)client/


all:
	make -C $(SERVER_PATH)
	cp $(SERVER_PATH)$(SERV) .
	make -C $(CLIENT_PATH)
	cp $(CLIENT_PATH)$(CLI) .

clean:
	make -C $(SERVER_PATH) clean
	make -C $(CLIENT_PATH) clean
fclean:
	make -C $(SERVER_PATH) fclean
	make -C $(CLIENT_PATH) fclean
	rm -f $(SERV)
	rm -f $(CLI)
re: fclean all

.PHONY: all clean fclean re
