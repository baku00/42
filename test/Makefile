NAME = so_long
SRCS = srcs
FUNCS = $(SRCS)/funcs
UTILS = $(FUNCS)/utils
INIT = $(FUNCS)/init
SRC = $(NAME).c \
		$(INIT)/init_game.c

OBJS = $(SRC:.c=.o)
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
INClUDES = includes

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	ar rc $(NAME).a $(MLX) $(OBJS)
	gcc -Wall -Werror -Wextra $(NAME).a includes/libft/libft.a -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	make -C ./mlx

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm $(NAME).a

re: fclean all
