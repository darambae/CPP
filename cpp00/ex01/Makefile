# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 11:11:04 by dabae             #+#    #+#              #
#    Updated: 2024/08/01 11:11:05 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Contact.cpp PhoneBook.cpp
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