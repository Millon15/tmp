# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 18:58:59 by vbrazas           #+#    #+#              #
#    Updated: 2018/08/11 17:35:03 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SRC_PATH = src/
OBJ_PATH = .obj/

CC = clang++
CFLAGS = #-Wall -Werror -Wextra

INC_PATH = includes/
IFLAGS = -I $(INC_PATH) -I ../../$(INC_PATH)

HFILES = Client
FILES = Client main

HDRS = $(addprefix $(INC_PATH), $(addsuffix .hpp, $(HFILES)))
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIB) -o $(NAME) 

$(LIB): 
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
fclean: mfclean
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
