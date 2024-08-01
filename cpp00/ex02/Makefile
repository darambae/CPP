# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 11:17:02 by dabae             #+#    #+#              #
#    Updated: 2024/08/01 11:17:03 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp
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