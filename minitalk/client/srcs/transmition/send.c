#include "../../client.h"

void	ft_send_transmition(t_transmition *transmition)
{
	int	i;

	i = 0;

	while (i < transmition->length)
	{
		if (transmition->signals[i++])
			kill(transmition->pid, SIGUSR2);
		else
			kill(transmition->pid, SIGUSR1);
		usleep(100);
	}
	printf("SENDED\n");
}
