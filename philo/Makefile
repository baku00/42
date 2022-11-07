# Program name
NAME	=philo

# Compilation config
CC		=gcc
INCLUDES=.
CFLAGS	=-Wall -Werror -Wextra -I$(INCLUDES)

# SRCS DIRS
SRCS_DIR	=srcs
LIBFT_DIR	=$(SRCS_DIR)/libft
ARGUMENTS_DIR	=$(SRCS_DIR)/arguments

# File sources
SRCS	=main.c \
			$(ARGUMENTS_DIR)/arguments.c \
			$(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_isdigit.c \
			$(LIBFT_DIR)/ft_strlen.c

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