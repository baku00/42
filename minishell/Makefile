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
EXIT_DIR		= $(BUILTINS_DIR)/exit
EXPORT_DIR		= $(BUILTINS_DIR)/export
ECHO_DIR		= $(BUILTINS_DIR)/echo
UNSET_DIR		= $(BUILTINS_DIR)/unset
UTILS_DIR	= utils
LISTS_DIR	= $(UTILS_DIR)/lists
STRINGS_DIR	= $(UTILS_DIR)/strings

# File sources
SRCS	=main_env.c \
			parser.c \
			$(INIT_DIR)/init_structs.c \
			$(INIT_DIR)/init_structs_more.c \
			$(INPUT_DIR)/getcmd.c \
			$(CD_DIR)/cd.c \
			$(ENV_DIR)/env.c \
			$(PWD_DIR)/pwd.c \
			$(EXIT_DIR)/exit.c \
			$(EXPORT_DIR)/export.c \
			$(ECHO_DIR)/echo.c \
			$(UNSET_DIR)/unset.c \
			$(LISTS_DIR)/free_list.c \
			$(STRINGS_DIR)/create_string.c \
			$(STRINGS_DIR)/init_string.c \
			$(STRINGS_DIR)/configure_string.c \
			$(STRINGS_DIR)/get_string.c \
			$(STRINGS_DIR)/free_string.c \
			$(STRINGS_DIR)/string_copy.c \
			$(BUILTINS_DIR)/exec_cmd.c


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