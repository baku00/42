#ifndef CLIENT_H
# define CLIENT_H
# include "includes/ft_printf/ft_printf.h"
# include "config/messages/errors.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
typedef struct s_transmition
{
	char	*message;
	int		state;
	char	c[2];
}	t_transmition;

int		ft_printf(const char *s, ...);
int		main(void);
void	ft_send_transmition(t_transmition *transmition);
void	ft_init_transmition(t_transmition *transmition, char **argv);
void	ft_exit(char *message);
int		*atob(char *message);
char	*btoa(int *binary, int length);
#endif
