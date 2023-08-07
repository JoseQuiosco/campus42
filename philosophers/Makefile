# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:59:35 by dvasco-m          #+#    #+#              #
#    Updated: 2023/08/03 17:33:18 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME=philo
CFLAGS= -Wall -Wextra -Werror -lpthread
SRC= main.c inits.c utils.c core.c
OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
