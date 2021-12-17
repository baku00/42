NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = get_next_line.c \
					get_next_line_utils.c

OFILES = get_next_line.o \
					get_next_line_utils.o

H_GNL = get_next_line.h
OBJS = $(SRCS:.c=.o)
SRCS = $(CFILES) $(H_GNL)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
