# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:59:35 by dvasco-m          #+#    #+#              #
#    Updated: 2023/08/08 17:04:23 by dvasco-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME=philo_bonus
CFLAGS= -Wall -Wextra -Werror -pthread
#FLAGBUG= -g -fsanitize=thread
SRC= main.c inits.c utils.c core.c
OBJ=$(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< ${<:.c.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(FLAGBUG) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
