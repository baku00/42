# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 04:08:13 by dgloriod          #+#    #+#              #
#    Updated: 2022/04/15 04:14:26 by dgloriod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc $(CFLAGS)
INCLUDES = ./includes
FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a
NAME =
CLIENT_NAME = client
SERVER_NAME = server

.c.o:
	$(CC) -c $< -o $@ -I$(FT_PRINTF)

$(NAME): all

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(CLIENT_NAME).o $(SERVER_NAME).o

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIB_FT_PRINTF_A) $(CLIENT_NAME).o
	$(CC) $(CFLAGS) $(CLIENT_NAME).o -o $(CLIENT_NAME) $(LIB_FT_PRINTF_A)

$(SERVER_NAME): $(LIB_FT_PRINTF_A) $(SERVER_NAME).o
	$(CC) $(CFLAGS) $(SERVER_NAME).c -o $(SERVER_NAME) $(LIB_FT_PRINTF_A)

$(LIB_FT_PRINTF_A):
	@$(MAKE) -C $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
