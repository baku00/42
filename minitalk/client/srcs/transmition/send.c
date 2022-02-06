#include "../../client.h"

void	ft_send_transmition(t_transmition *transmition)
{
	sigset_t set;
	int	i;

	i = 0;
	sigemptyset(&set);

	sigprocmask(SIG_BLOCK, &set, NULL);

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
