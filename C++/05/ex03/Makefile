# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:30:42 by dvasco-m          #+#    #+#              #
#    Updated: 2023/12/01 00:11:34 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
#TEST = test
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
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