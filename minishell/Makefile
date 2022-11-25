# Program name
NAME	=minishell

# Compilation config
CC		=gcc
INCLUDES=.
CFLAGS	=-Wall -Werror -Wextra -I$(INCLUDES) -L/usr/local/lib -I/usr/local/include -lreadline
LIBFT	=libft
LIBFT_A =$(LIBFT)/libft.a

# DIRS
INIT_DIR	= init
INPUT_DIR	= input
BUILTINS_DIR = builtins
CD_DIR		= $(BUILTINS_DIR)/cd
ENV_DIR		= $(BUILTINS_DIR)/env
PWD_DIR		= $(BUILTINS_DIR)/pwd
BUILTINS_UTILS_DIR		= $(BUILTINS_DIR)/utils
UTILS_DIR	= utils
LISTS_DIR	= $(UTILS_DIR)/lists

# File sources
SRCS	=main.c \
			$(INIT_DIR)/init_structs.c \
			$(INIT_DIR)/init_structs_more.c \
			$(INPUT_DIR)/getcmd.c \
			$(CD_DIR)/cd.c \
			$(ENV_DIR)/env.c \
			$(PWD_DIR)/pwd.c \
			$(BUILTINS_UTILS_DIR)/dir.c \
			$(BUILTINS_UTILS_DIR)/path.c \
			$(LISTS_DIR)/free_list.c


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