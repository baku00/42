NAME = so_long
SRCS = srcs
FUNCS = $(SRCS)/funcs
UTILS = $(FUNCS)/utils
INIT = $(FUNCS)/init
CALL = $(INIT)/call
ITEM = $(CALL)/item
SRC = $(NAME).c \
		$(UTILS)/error.c \
		$(INIT)/init_game.c \
		$(INIT)/init_map.c \
		$(CALL)/init_window.c \
		$(CALL)/init_item.c \
		$(CALL)/init_define.c \
		$(ITEM)/init_wall.c \
		$(ITEM)/init_player.c \
		$(ITEM)/init_exit.c \
		$(ITEM)/init_empty.c \
		$(ITEM)/init_coin.c

OBJS = $(SRC:.c=.o)
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
INClUDES = includes
LIBFT = $(INClUDES)/libft
MAKE_LIBFT = -C $(LIBFT)
LIBFT_A = $(LIBFT)/libft.a

GNL = $(INClUDES)/get_next_line
MAKE_GNL = -C $(GNL)
GNL_A = $(GNL)/get_next_line.a

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT_A) $(GNL_A)
	ar rc $(NAME).a $(OBJS) $(MLX)
	gcc -Wall -Werror -Wextra $(NAME).a $(LIBFT_A) $(GNL_A) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	make -C ./mlx

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME)

$(LIBFT_A):
	make $(MAKE_LIBFT)
	OBJS += $(LIBFT_A)

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
