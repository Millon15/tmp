# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/08/09 21:12:45 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERV = server
CLI = client

SRC_PATH =
SERVER_PATH = $(SRC_PATH)serv/
CLIENT_PATH = $(SRC_PATH)cli/


all: $(SERV) $(CLI)

$(SERV):
	make -C $(SERVER_PATH)
	mv $(SERVER_PATH)$(SERV) .

$(CLI):
	make -C $(CLIENT_PATH)
	mv $(CLIENT_PATH)$(CLI) .

clean:
	make clean -C $(SERVER_PATH)
	make clean -C $(CLIENT_PATH)
fclean:
	make fclean -C $(SERVER_PATH)
	make fclean -C $(CLIENT_PATH)
re: fclean all

.PHONY: all clean fclean re
