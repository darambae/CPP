# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 11:01:09 by dabae             #+#    #+#              #
#    Updated: 2024/07/19 11:12:42 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(OBJ): %.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re