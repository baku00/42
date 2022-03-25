#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include "./includes/ft_printf/ft_printf.h"

typedef struct s_transmission
{
	size_t	i;
	size_t	j;
	int		pid;
	char	*message;
	char	*signals_temp;
	size_t	length_loop;
	size_t	length;
	int		state;
	char	c[2];
}	t_transmission;

typedef struct s_int_to_binary
{
	int		i;
	int		from;
	int		move_bytes;
	int		can_convert;
	char	*result;
}	t_int_to_binary;
#endif
