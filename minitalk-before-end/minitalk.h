#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "./includes/ft_printf/ft_printf.h"
typedef struct s_transmission
{
	size_t	i;
	size_t	j;
	int		pid;
	char	*message;
	int		*signals;
	char	*signals_temp;
	size_t	length_loop;
	size_t	length;
	int		state;
	char	c[2];
}	t_transmission;
#endif
