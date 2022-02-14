NAME = so_long

FOLDER = basic
FOLDER_BONUS = bonus

SRCS_DIR_BONUS = $(FOLDER_BONUS)/srcs
SRCS_DIR = $(FOLDER)/srcs
FUNCTIONS_DIR = $(SRCS_DIR)/functions
FUNCTIONS_DIR_BONUS = $(SRCS_DIR_BONUS)/functions
FILES_DIR = $(FUNCTIONS_DIR)/files
FILES_DIR_BONUS = $(FUNCTIONS_DIR_BONUS)/files
SRCS = $(FOLDER)/$(NAME).c \
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

SRCS_BONUS = $(FOLDER_BONUS)/$(NAME)_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/ft_exit_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/ft_create_map_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/set_images_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/key_hook_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/move_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/mlx_close_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/get_collectible_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/print_ath_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/win_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/lose_bonus.c \
		$(FUNCTIONS_DIR_BONUS)/zanimations.c \
		$(FILES_DIR_BONUS)/ft_check_char_bonus.c \
		$(FILES_DIR_BONUS)/ft_check_file_bonus.c

ifeq ($(shell uname), Linux)
KEYS = -D ESCAPE=65307 -D UP=119 -D LEFT=97 -D RIGHT=100 -D DOWN=115
else
KEYS = -D ESCAPE=53 -D UP=13 -D LEFT=0 -D RIGHT=2 -D DOWN=1
endif
CFLAGS = -Wall -Werror -Wextra $(KEYS)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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
ifdef WITH_BONUS
	COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(NAME)_bonus.a $(LIBFT_A) $(GNL_A) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)
else
	COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(NAME).a $(LIBFT_A) $(GNL_A) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)
endif
else
CREATE_MLX = cp -R mlx_mac mlx
MLX = $(MLX_DIR)/libmlx.a
ifdef WITH_BONUS
	COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS_BONUS) -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx -o $(NAME)
else
	COMPILE = gcc -Wall -Werror -Wextra $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS) -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx -o $(NAME)
endif
endif

all: $(NAME)

ifdef WITH_BONUS
$(NAME): $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS_BONUS)
	ar rc $(NAME)_bonus.a $(OBJS_BONUS)
	$(COMPILE)
else
$(NAME): $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	$(COMPILE)
endif

$(MLX):
	$(CREATE_MLX)
	make -C ./mlx

bonus:
	$(MAKE) WITH_BONUS=1

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME) $(NAME).a
	rm -rf $(NAME)_bonus.a
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

.PHONY: 	all clean fclean re bonus
