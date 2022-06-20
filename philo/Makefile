# Program name
NAME	=FILE_NAME

# Compilation config
CC		=gcc
INCLUDES=.
CFLAGS	=-Wall -Werror -Wextra -I$(INCLUDES)

# File sources
SRCS	=main.c

# File objects
OBJS	=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test:
	./${NAME}

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test