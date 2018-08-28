# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 19:52:44 by vbrazas           #+#    #+#              #
#    Updated: 2018/08/28 13:37:42 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calculate_prime

SRC_PATH = src/
OBJ_PATH = .obj/

CC = clang++
CFLAGS = -std=c++11 -Wall -Werror -Wextra -O3

INC_PATH = includes/
IFLAGS = -I $(INC_PATH)

HFILES = Parser Tree Computer
CLASSES = Parser Tree Computer
FILES = main

HDRS = $(addprefix $(INC_PATH), $(addsuffix .hpp, $(HFILES)))
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(FILES)))
SRCS += $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(CLASSES)))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(IFLAGS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)
fclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
re: fclean all

.PHONY: all clean fclean re
