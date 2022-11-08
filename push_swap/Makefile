NAME = push_swap

SRCS = main.c \
	arguments/arguments.c \
	arguments/arguments_utils.c \
	array/ft_array_dup.c \
	array/ft_array_length.c \
	array/ft_free_array.c \
	sort/sort_small.c \
	sort/sort_big.c \
	sort/is_sorted.c \
	sort/operations.c
FT_PRINTF_A = includes/ft_printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_A)
	gcc -Wall -Werror -Wextra $(OBJS) $(FT_PRINTF_A) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C includes/ft_printf

fclean: clean
	rm -rf $(NAME)
	make fclean -C includes/ft_printf

re:	fclean all

$(FT_PRINTF_A):
	make -C includes/ft_printf

.PHONY: all clean fclean re