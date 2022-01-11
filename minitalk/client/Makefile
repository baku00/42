NAME = client
INCLUDES = includes
FT_PRINTF = $(INCLUDES)/ft_printf
FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a
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

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	gcc -Wall -Werror -Wextra $(NAME).a $(FT_PRINTF_A) -o $(NAME)


$(FT_PRINTF_A):
	make -C $(FT_PRINTF)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME).a

re: fclean all
