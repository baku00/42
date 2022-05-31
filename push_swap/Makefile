NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(KEYS)

INCLUDES=includes
CHECKERS=checkers
PARSERS=parsers
CONVERTERS=converters
LISTES=listes
NUMBERS=numbers

FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

SRCS = $(NAME).c \
		$(CHECKERS)/arguments.c \
		$(PARSERS)/arguments.c \
		$(CONVERTERS)/convert_to_numbers.c \
		$(LISTES)/ft_lstadd_back.c \
		$(LISTES)/ft_lstadd_front.c \
		$(LISTES)/ft_lstclear.c \
		$(LISTES)/ft_lstdelone.c \
		$(LISTES)/ft_lstiter.c \
		$(LISTES)/ft_lstlast.c \
		$(LISTES)/ft_lstmap.c \
		$(LISTES)/ft_lstnew.c \
		$(LISTES)/ft_lstnext.c \
		$(LISTES)/ft_lstsize.c \
		$(LISTES)/ft_save.c \
		$(NUMBERS)/set_index.c \
		operations.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FT_PRINTF_A) -o $(NAME)

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJS)

fclean:
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAME)

$(LIB_FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF)

norme:
	norminette ./

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus norme
