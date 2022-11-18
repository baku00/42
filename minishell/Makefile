# Program name
NAME	=minishell

# Compilation config
CC		=gcc
INCLUDES=.
CFLAGS	=-Wall -Werror -Wextra -I$(INCLUDES)
LIBFT	=libft
LIBFT_A =$(LIBFT)/libft.a

# File sources
SRCS	=main.c

# File objects
OBJS	=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C ./libft

test:
	./${NAME}

clean:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re test