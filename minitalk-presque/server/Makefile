NAME = server
INCLUDES = includes
PRINTF = $(INCLUDES)/ft_printf
PRINTF_A = $(PRINTF)/libftprintf.a
DIR_SRCS = srcs
DIR_FUNCTIONS = $(DIR_SRCS)/functions
DIR_CONVERT = $(DIR_FUNCTIONS)/convert
DIR_TRANSMITION = $(DIR_SRCS)/transmition

SRCS = $(NAME).c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	gcc -Wall -Werror -Wextra $(NAME).a $(PRINTF_A) -o $(NAME)

$(PRINTF_A):
	make -C $(PRINTF)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a
	rm -rf $(NAME)

re: fclean all
