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
					ft_printf.c \
					$(FUNCS)/ft_putunsigned_fd.c \
					$(FUNCS)/ft_intlen.c \
					$(PRINT)/ft_print_c.c \
					$(PRINT)/ft_print_d.c \
					$(PRINT)/ft_print_u.c \
					$(PRINT)/ft_print_p.c \
					$(PRINT)/ft_print_s.c \
					$(PRINT)/ft_print_x.c

OFILES = $(LIBFT)/ft_atoi.o \
					$(LIBFT)/ft_bzero.o \
					$(LIBFT)/ft_calloc.o \
					$(LIBFT)/ft_isalnum.o \
					$(LIBFT)/ft_isalpha.o \
					$(LIBFT)/ft_isascii.o \
					$(LIBFT)/ft_isdigit.o \
					$(LIBFT)/ft_isprint.o \
					$(LIBFT)/ft_itoa.o \
					$(LIBFT)/ft_memchr.o \
					$(LIBFT)/ft_memcmp.o \
					$(LIBFT)/ft_memcpy.o \
					$(LIBFT)/ft_memmove.o \
					$(LIBFT)/ft_memset.o \
					$(LIBFT)/ft_putchar_fd.o \
					$(LIBFT)/ft_putendl_fd.o \
					$(LIBFT)/ft_putnbr_fd.o \
					$(LIBFT)/ft_putstr_fd.o \
					$(LIBFT)/ft_split.o \
					$(LIBFT)/ft_strchr.o \
					$(LIBFT)/ft_strdup.o \
					$(LIBFT)/ft_striteri.o \
					$(LIBFT)/ft_strjoin.o \
					$(LIBFT)/ft_strlcat.o \
					$(LIBFT)/ft_strlcpy.o \
					$(LIBFT)/ft_strlen.o \
					$(LIBFT)/ft_strmapi.o \
					$(LIBFT)/ft_strncmp.o \
					$(LIBFT)/ft_strnstr.o \
					$(LIBFT)/ft_strrchr.o \
					$(LIBFT)/ft_strtrim.o \
					$(LIBFT)/ft_substr.o \
					$(LIBFT)/ft_tolower.o \
					$(LIBFT)/ft_toupper.o \
					ft_printf.o \
					$(FUNCS)/ft_putunsigned_fd.o \
					$(FUNCS)/ft_intlen.o \
					$(PRINT)/ft_print_c.o \
					$(PRINT)/ft_print_d.o \
					$(PRINT)/ft_print_u.o \
					$(PRINT)/ft_print_p.o \
					$(PRINT)/ft_print_s.o \
					$(PRINT)/ft_print_x.o

H_LIB = ft_printf.h \
					$(LIBFT)/libft.h
LIBFT = includes/libft
SRC = srcs
PRINT = $(SRC)/print
FUNCS = $(SRC)/funcs
OBJS = $(SRCS:.c=.o)
SRCS = $(CFILES) $(H_LIB)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re $(EXTENDS)
