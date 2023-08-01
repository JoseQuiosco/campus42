# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:59:35 by dvasco-m          #+#    #+#              #
#    Updated: 2023/07/31 19:50:32 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
#CC= gcc -g
NAME=philosopher
CFLAGS= -Wall -Wextra -Werror -lpthread
SRC= main.c
OBJ=$(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)


re: fclean all
