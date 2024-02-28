# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 20:27:42 by dvasco            #+#    #+#              #
#    Updated: 2024/02/27 20:28:15 by dvasco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=mutantstack
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
CC=c++
FLAGS=-Wall -Werror -Wextra
VERSION=-std=c++98

%.o: %.cpp
	$(CC) $(FLAGS) $(VERSION) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(FLAGS) $(VERSION) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
