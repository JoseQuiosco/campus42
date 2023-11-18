# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:30:42 by dvasco-m          #+#    #+#              #
#    Updated: 2023/11/18 19:24:53 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materias
TEST = test
SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp
#SRC2 = 
CC = c++
OBJ = $(SRC:.cpp=.o)
#OBJ2 = $(SRC2:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

#$(TEST): $(OBJ2)
#	$(CC) $(OBJ2) -o $(TEST)

clean:
	rm -rf $(OBJ)
#	rm -rf $(OBJ2)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
#	rm -rf $(OBJ2)
#	rm -rf $(TEST)

re: fclean all

.PHONY: all clean fclean re