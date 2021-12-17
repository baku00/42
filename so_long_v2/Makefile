NAME = so_long
FUNCS = srcs/funcs
INIT = $(FUNCS)/init
EVENTS = $(FUNCS)/events
UTILS = $(EVENTS)/utils
MOVE = $(EVENTS)/move
CHECK = $(EVENTS)/check
ENABLE = $(EVENTS)/enable
MESSAGE = $(INIT)/message
PLATEFORME = $(INIT)/plateforme
PUT = $(PLATEFORME)/put
REMOVE = $(PLATEFORME)/remove
VERIFY = $(PLATEFORME)/verify
VALID = $(VERIFY)/valid
STR = $(FUNCS)/str
SRCS = $(NAME).c \
		$(INIT)/init_game.c \
		$(FUNCS)/error.c \
		$(MESSAGE)/init_error_message.c \
		$(MESSAGE)/init_message.c \
		$(PLATEFORME)/get_line.c \
		$(PLATEFORME)/init_define.c \
		$(PLATEFORME)/init_keys.c \
		$(PLATEFORME)/init_map.c \
		$(PLATEFORME)/init_window.c \
		$(PLATEFORME)/init_point.c \
		$(PLATEFORME)/init_contains.c \
		$(PLATEFORME)/init_coin.c \
		$(REMOVE)/remove_coin.c \
		$(ENABLE)/enable_door.c \
		$(VERIFY)/verify_map.c \
		$(VALID)/valid_map_shape.c \
		$(VALID)/valid_contains.c \
		$(VALID)/contains_object.c \
		$(PUT)/put_image.c \
		$(PUT)/put_wall.c \
		$(PUT)/put_empty.c \
		$(PUT)/put_exit.c \
		$(PUT)/put_player.c \
		$(PUT)/put_coin.c \
		$(STR)/is_at.c \
		$(UTILS)/close.c \
		$(UTILS)/win.c \
		$(UTILS)/print_move.c \
		$(EVENTS)/hook.c \
		$(MOVE)/up.c \
		$(MOVE)/down.c \
		$(MOVE)/left.c \
		$(MOVE)/right.c \
		$(MOVE)/move.c \
		$(CHECK)/coin.c \
		$(CHECK)/door.c \
		$(CHECK)/wall.c \
		$(STR)/is_n_only.c
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
	ar rc $(NAME).a $(OBJS) $(MLX)
	gcc -Wall -Werror -Wextra $(NAME).a $(LIBFT_A) $(GNL_A) -lmlx -Lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	make -C ./mlx

clean: $(LIBFT_A)_clean $(GNL_A)_clean
	rm -rf $(OBJS)

fclean: clean $(LIBFT_A)_fclean $(GNL_A)_fclean
	rm -rf $(NAME) $(NAME).a

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
