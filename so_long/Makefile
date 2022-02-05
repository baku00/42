NAME = so_long

SRCS_DIR = srcs
FUNCTIONS_DIR = $(SRCS_DIR)/functions
FILES_DIR = $(FUNCTIONS_DIR)/files

SRCS = $(NAME).c \
		$(FUNCTIONS_DIR)/ft_exit.c \
		$(FUNCTIONS_DIR)/ft_create_map.c \
		$(FUNCTIONS_DIR)/set_images.c \
		$(FUNCTIONS_DIR)/key_hook.c \
		$(FUNCTIONS_DIR)/move.c \
		$(FUNCTIONS_DIR)/mlx_close.c \
		$(FUNCTIONS_DIR)/get_collectible.c \
		$(FUNCTIONS_DIR)/print_ath.c \
		$(FUNCTIONS_DIR)/win.c \
		$(FILES_DIR)/ft_check_char.c \
		$(FILES_DIR)/ft_check_file.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./mlx
INClUDES = includes

LIBFT = $(INClUDES)/libft
MAKE_LIBFT = -C $(LIBFT)
LIBFT_A = $(LIBFT)/libft.a

GNL = $(INClUDES)/get_next_line
MAKE_GNL = -C $(GNL)
GNL_A = $(GNL)/get_next_line.a

ifeq ($(shell uname), Linux)
CREATE_MLX = cp -R mlx_linux mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
ESCAPE = 65307
UP = 119
LEFT = 97
RIGHT = 100
DOWN = 115
COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(NAME).a $(LIBFT_A) $(GNL_A) -D ESCAPE=$(ESCAPE) -D LEFT=$(LEFT) -D RIGHT=$(RIGHT) -D DOWN=$(DOWN) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)
else
CREATE_MLX = cp -R mlx_mac mlx
MLX = $(MLX_DIR)/libmlx.a
ESCAPE = 65307
UP = 119
LEFT = 97
RIGHT = 100
DOWN = 115
COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS) -D ESCAPE=$(ESCAPE) -D LEFT=$(LEFT) -D RIGHT=$(RIGHT) -D DOWN=$(DOWN) -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx -o $(NAME)
endif

all: $(NAME)

$(NAME): $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	$(COMPILE)

$(MLX):
	$(CREATE_MLX)
	make -C ./mlx

bonus:
	rm -rf $(OBJS)
	rm -rf $(NAME) $(NAME).a
	$(MAKE) BONUS=1

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME) $(NAME).a
	rm -rf mlx

$(LIBFT_A):
	make $(MAKE_LIBFT)

$(LIBFT_A)_clean:
	make clean $(MAKE_LIBFT)

$(LIBFT_A)_fclean:
	make fclean $(MAKE_LIBFT)

$(GNL_A):
	make $(MAKE_GNL)

$(GNL_A)_clean:
	make clean $(MAKE_GNL)

$(GNL_A)_fclean:
	make fclean $(MAKE_GNL)

re: fclean $(NAME) $(LIBFT_A)_fclean $(GNL_A)_fclean
