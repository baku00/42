NAME = so_long
SRCS = srcs
FUNCS = $(SRCS)/funcs
UTILS = $(FUNCS)/utils
INIT = $(FUNCS)/init
SRC = $(INIT)/init_map.c \
		$(INIT)/init_game.c \
		$(NAME).c

OBJS = $(SRC:.c=.o)
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
INClUDES = includes

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	gcc -Wall -Werror -Wextra $(MLX) $(OBJS) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	make -C ./mlx

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
