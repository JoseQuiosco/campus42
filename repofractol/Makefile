NAME = fractol

FLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

SRC = fractol.c src/fract_utils1.c src/fract_utils2.c src/fract_utils3.c src/fract_colors.c \
	  src/fract_fractals1.c src/fract_fractals2.c src/fract_keyboard.c src/fract_mouse.c \

OBJS = $(SRC:.c=.o)

.c.o:
	gcc -c $(FLAGS) -c $< -o $(<:.c=.o)
	
all: $(NAME)

$(NAME): LIB $(OBJS)
	gcc -g $(OBJS) -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"  libft/libft.a  mlx42/libmlx42.a -o $(NAME)

bonus: $(NAME) clean

LIB:
	$(MAKE) -C ./libft

clean:
	rm -f *.o
	rm -f ./src/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

