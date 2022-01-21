#include "../../server.h"

void	ft_send_transmition(t_transmition *transmition)
{
	int	i;

	i = 0;
	printf("\nSending...\n");
	while (i < transmition->length)
	{
		if (transmition->signals[i])
			kill(transmition->pid, SIGUSR1);
		else
			kill(transmition->pid, SIGUSR2);
		printf("%d", transmition->signals[i++]);
		if (!(i % 8))
			printf("\n");
	}
	printf("BTOA: %s\n", btoa(transmition->signals, transmition->length));
}
