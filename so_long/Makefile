NAME = so_long
FUNCS = srcs/funcs
MAP = $(FUNCS)/map
STR = $(FUNCS)/str
SRCS = $(FUNCS)/error.c \
				$(FUNCS)/events/hook.c \
				$(FUNCS)/item/get_point.c \
				$(FUNCS)/events/close.c \
				$(FUNCS)/events/move/check/checkWall.c \
				$(FUNCS)/events/move/check/checkDoor.c \
				$(FUNCS)/utils/win.c \
				$(FUNCS)/utils/print_move.c \
				$(FUNCS)/events/move/check/checkCoin.c \
				$(FUNCS)/events/move/remove/removeCoin.c \
				$(FUNCS)/events/move/up.c \
				$(FUNCS)/events/move/down.c \
				$(FUNCS)/events/move/right.c \
				$(FUNCS)/events/move/left.c \
				$(MAP)/valid_map.c \
				$(MAP)/valid_shape.c \
				$(STR)/is_n_only.c \
				$(STR)/is_at.c \
				$(NAME).c
OBJS = $(SRCS:.c=.o)
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

$(NAME): $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS)
	gcc $(MLX) $(LIBFT_A) $(GNL_A) $(OBJS) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	make -C ./mlx

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME)

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
