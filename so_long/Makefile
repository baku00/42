NAME = so_long

FOLDER = basic
FOLDER_BONUS = bonus

SRCS_DIR = $(FOLDER)/srcs
SRCS_DIR_BONUS = $(FOLDER_BONUS)/srcs

FUNCTIONS_DIR = $(SRCS_DIR)/functions
FUNCTIONS_DIR_BONUS = $(SRCS_DIR_BONUS)/functions

INITIER_DIR = $(SRCS_DIR)/initier
INITIER_DIR_BONUS = $(SRCS_DIR_BONUS)/initier

FILES_DIR = $(FUNCTIONS_DIR)/files
FILES_DIR_BONUS = $(FUNCTIONS_DIR_BONUS)/files

SRCS = $(FOLDER)/$(NAME).c \
		$(INITIER_DIR)/init.c \
		$(INITIER_DIR)/init_file.c \
		$(INITIER_DIR)/init_window.c \
		$(FUNCTIONS_DIR)/ft_exit.c \
		$(FUNCTIONS_DIR)/ft_create_map.c \
		$(FUNCTIONS_DIR)/key_hook.c \
		$(FUNCTIONS_DIR)/get_collectible.c \
		$(FUNCTIONS_DIR)/win.c \
		$(FILES_DIR)/ft_check_file.c \
		$(INITIER_DIR)/init_elements.c \
		$(FILES_DIR)/ft_check_char.c \
		$(FUNCTIONS_DIR)/mlx_close.c

SRCS_WITHOUT_BONUS = $(FUNCTIONS_DIR)/move.c \
						$(FUNCTIONS_DIR)/print_ath.c \
						$(FUNCTIONS_DIR)/set_images.c


SRCS_BONUS = $(INITIER_DIR_BONUS)/init_elements_bonus.c \
				$(FILES_DIR_BONUS)/ft_check_char_bonus.c \
				$(FUNCTIONS_DIR_BONUS)/mlx_close_bonus.c \
				$(FUNCTIONS_DIR_BONUS)/set_images_bonus.c \
				$(FUNCTIONS_DIR_BONUS)/lose_bonus.c \
				$(FUNCTIONS_DIR_BONUS)/move_bonus.c \
				$(FUNCTIONS_DIR_BONUS)/print_ath_bonus.c \

SRCS_BONUS += $(SRCS)
SRCS_WITHOUT_BONUS += $(SRCS)

ifeq ($(shell uname), Linux)
KEYS = -D ESCAPE=65307 -D UP=119 -D LEFT=97 -D RIGHT=100 -D DOWN=115 -D PLATEFORME=1
else
KEYS = -D ESCAPE=53 -D UP=13 -D LEFT=0 -D RIGHT=2 -D DOWN=1
endif
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(KEYS)

ifdef WITH_BONUS
	CFLAGS += -D WITH_BONUS=1
endif

OBJS = $(SRCS_WITHOUT_BONUS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MLX_DIR = ./mlx
INClUDES = includes

LIBFT = ./libft
MAKE_LIBFT = -C $(LIBFT)
LIBFT_A = $(LIBFT)/libft.a

GNL = $(INClUDES)/get_next_line
MAKE_GNL = -C $(GNL)
GNL_A = $(GNL)/get_next_line.a

ifeq ($(shell uname), Linux)
	ARCH = linux
	MLX_LIB = libmlx_Linux.a
else
	ARCH = mac
	MLX_LIB = libmlx.a
endif

CREATE_MLX = cp -R mlx_$(ARCH) mlx
MLX = $(MLX_DIR)/$(MLX_LIB)

COMPILE = $(CC) $(CFLAGS) $(MLX)
ifdef WITH_BONUS
	COMPILE += $(OBJS_BONUS)
else
	COMPILE += $(OBJS)
endif

COMPILE += $(LIBFT_A) $(GNL_A)

ifeq ($(shell uname), Linux)
	COMPILE += -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)
else
	COMPILE +=  -lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx -o $(NAME)
endif

all: $(NAME)

ifdef WITH_BONUS
$(NAME): fclean $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS_BONUS)
	$(COMPILE)
else
$(NAME): $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS)
	$(COMPILE)
endif

$(MLX):
	$(CREATE_MLX)
	make -C ./mlx

bonus: $(OBJS_BONUS)
	make WITH_BONUS="1"

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME)
	rm -rf mlx

norme:
	norminette basic
	norminette bonus
	norminette includes
	norminette libft

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

.PHONY: 	all clean fclean re bonus norme
