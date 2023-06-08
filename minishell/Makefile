NAME=minishell
CC=gcc
#CFLAGS=-Wall -Wextra -Werror -g
LFLAGS=-L./libft
IFLAGS=-I./libft/include
LIBFT=libft/libft.a
LIBS=-lreadline -lft
COMPILED_OBJS=$(shell find . -name '*.o')
SRC:=$(shell find . -maxdepth 1 -name '*.c')
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(DBG)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o3 -c $< -o $@ $(DBG)

$(LIBFT):
	$(MAKE) bonus -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(COMPILED_OBJS)

re: fclean all
