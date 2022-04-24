CLIENT_NAME = client
SERVER_NAME = server
NAMES = $(CLIENT_NAME) $(SERVER_NAME)

INCLUDES = ./includes

FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

OBJS = $(CFILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAMES)

$(CLIENT_NAME): $(OBJS) $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_NAME).c $(OBJS) $(LIB_FT_PRINTF_A) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_NAME).c $(LIB_FT_PRINTF_A) -o $(SERVER_NAME)

$(LIB_FT_PRINTF_A):
	@$(MAKE) -C $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
