# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 14:58:36 by dabae             #+#    #+#              #
#    Updated: 2024/07/29 15:19:00 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap 
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
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