NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(KEYS)

INCLUDES=includes
CHECKERS=checkers
PARSERS=parsers
CONVERTERS=converters
NUMBERS=numbers
SORTERS=sorters

FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

SRCS = $(NAME).c \
		$(CHECKERS)/arguments.c \
		$(PARSERS)/arguments.c \
		$(CONVERTERS)/convert_to_numbers.c \
		$(NUMBERS)/set_index.c \
		$(SORTERS)/sort.c \
		$(SORTERS)/sort_utils.c \
		free.c \
		operations.c

OBJS = $(SRCS:.c=.o)

CHECKER = checker

ifeq ($(shell uname), Linux)
	CMDS = cp $(CHECKER)_linux $(CHECKER)
else
	CMDS = cp $(CHECKER)_Mac $(CHECKER)
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FT_PRINTF_A) -o $(NAME)
	$(CMDS)

test:
	bash ./tests/42.sh

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAME)
	rm -rf $(CHECKER)

$(LIB_FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF)

norme:
	norminette ./

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus norme
