# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasco <dvasco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 18:15:38 by dvasco-m          #+#    #+#              #
#    Updated: 2024/02/22 18:57:47 by dvasco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = 

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c \
	  psw_utils1.c psw_utils2.c psw_utils3.c psw_utils4.c psw_utils5.c \
	  psw_utils6.c psw_utils7.c psw_utils8.c psw_utils9.c psw_utils10.c \
	  psw_utils11.c psw_utils12.c psw_utils13.c psw_utils14.c psw_utils15.c \
	  psw_utils16.c utilsptf1.c utilsptf2.c utilsptf3.c utilsptf4.c \
	  utilsptf5.c utilsptf6.c utilsptf7.c utilsptf8.c utilsptf9.c \
	  utilsptf10.c utilsptf11.c utilsptf12.c utilsptf13.c utilsptf14.c \
	  utilsptf15.c utilsptf16.c utilsptf17.c check_utils.c ft_printf.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

.c.o:
	gcc -c $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft.h
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus: clean $(OBJS) $(BONUS_OBJS) libft.h
	ar -cr $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:
	clean fclean re all
