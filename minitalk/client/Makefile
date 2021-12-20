NAME = client
INCLUDES = includes
FT_PRINTF = $(INCLUDES)/ft_printf
FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

SRCS = $(NAME).c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_A) $(OBJS)
	ar rc $(NAME).a $(OBJS)
	gcc -Wall -Werror -Wextra $(NAME).a $(FT_PRINTF_A) -o $(NAME)


$(FT_PRINTF_A):
	make -C $(FT_PRINTF)
