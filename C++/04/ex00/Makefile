# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:30:42 by dvasco-m          #+#    #+#              #
#    Updated: 2023/11/16 23:40:12 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
TEST = test
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
SRC2 = testRandom.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
CC = c++
OBJ = $(SRC:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(TEST): $(OBJ2)
	$(CC) $(OBJ2) -o $(TEST)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ2)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	rm -rf $(OBJ2)
	rm -rf $(TEST)

re: fclean all

.PHONY: all clean fclean re