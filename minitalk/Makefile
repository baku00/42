CLIENT_NAME = client
SERVER_NAME = server
NAMES = $(CLIENT_NAME) $(SERVER_NAME)

INCLUDES = ./includes

FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

CFILES = send_message.c

OBJS = $(CFILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAMES)

$(CLIENT_NAME): $(OBJS) $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_NAME).c $(OBJS) $(LIB_FT_PRINTF_A) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_NAME).c $(LIB_FT_PRINTF_A) -o $(SERVER_NAME)

$(LIB_FT_PRINTF_A):
	@$(MAKE) -C $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
