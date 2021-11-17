NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = $(LIBFT)/ft_atoi.c \
					$(LIBFT)/ft_bzero.c \
					$(LIBFT)/ft_calloc.c \
					$(LIBFT)/ft_isalnum.c \
					$(LIBFT)/ft_isalpha.c \
					$(LIBFT)/ft_isascii.c \
					$(LIBFT)/ft_isdigit.c \
					$(LIBFT)/ft_isprint.c \
					$(LIBFT)/ft_itoa.c \
					$(LIBFT)/ft_memchr.c \
					$(LIBFT)/ft_memcmp.c \
					$(LIBFT)/ft_memcpy.c \
					$(LIBFT)/ft_memmove.c \
					$(LIBFT)/ft_memset.c \
					$(LIBFT)/ft_putchar_fd.c \
					$(LIBFT)/ft_putendl_fd.c \
					$(LIBFT)/ft_putnbr_fd.c \
					$(LIBFT)/ft_putstr_fd.c \
					$(LIBFT)/ft_split.c \
					$(LIBFT)/ft_strchr.c \
					$(LIBFT)/ft_strdup.c \
					$(LIBFT)/ft_striteri.c \
					$(LIBFT)/ft_strjoin.c \
					$(LIBFT)/ft_strlcat.c \
					$(LIBFT)/ft_strlcpy.c \
					$(LIBFT)/ft_strlen.c \
					$(LIBFT)/ft_strmapi.c \
					$(LIBFT)/ft_strncmp.c \
					$(LIBFT)/ft_strnstr.c \
					$(LIBFT)/ft_strrchr.c \
					$(LIBFT)/ft_strtrim.c \
					$(LIBFT)/ft_substr.c \
					$(LIBFT)/ft_tolower.c \
					$(LIBFT)/ft_toupper.c \
					$(PRINT)/ft_print_c.c \
					$(PRINT)/ft_print_d.c \
					$(PRINT)/ft_print_p.c \
					$(PRINT)/ft_print_pourcent.c \
					$(PRINT)/ft_print_s.c \
					$(PRINT)/ft_print_x.c

H_LIB = ft_printf.h \
					$(LIBFT)/libft.h
LIBFT = includes/libft
SRC = srcs
PRINT = $(SRC)/print
OBJS = $(SRCS:.c=.o)
SRCS = $(CFILES) $(H_LIB)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re $(EXTENDS)
