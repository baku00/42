#ifndef MINITALK_H
# define MINITALK_H
# include "./includes/ft_printf/ft_printf.h"
typedef struct s_transmition
{
	int		pid;
	char	*message;
	int		*signals;
	size_t	length;
	int		state;
	char	c[2];
}	t_transmition;
#endif
