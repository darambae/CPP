# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 14:58:36 by dabae             #+#    #+#              #
#    Updated: 2024/08/23 16:53:44 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap 
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
all: $(NAME)
$(OBJ): %.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re