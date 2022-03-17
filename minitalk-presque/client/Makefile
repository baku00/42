NAME = client
INCLUDES = includes
PRINTF = $(INCLUDES)/ft_printf
PRINTF_A = $(PRINTF)/libftprintf.a
DIR_SRCS = srcs
DIR_FUNCTIONS = $(DIR_SRCS)/functions
DIR_CONVERT = $(DIR_FUNCTIONS)/convert
DIR_TRANSMITION = $(DIR_SRCS)/transmition

SRCS = $(NAME).c \
		$(DIR_FUNCTIONS)/exit.c \
		$(DIR_CONVERT)/atob.c \
		$(DIR_CONVERT)/btoa.c \
		$(DIR_TRANSMITION)/init.c \
		$(DIR_TRANSMITION)/send.c \

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	gcc -Wall -Werror -Wextra $(NAME).a $(PRINTF_A) -o $(NAME)


$(PRINTF_A):
	make -C $(PRINTF)

clean:
	make clean -C $(PRINTF)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(PRINTF)
	rm -rf $(NAME).a
	rm -rf $(NAME)

re: fclean all
