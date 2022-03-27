#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	static int				count;
	static t_transmission	trans;

	((void) context, (void) signum);
	trans.c[1] = 0;
	if (!trans.state)
		trans.c[0] = 0;
	if (signum == SIGUSR2)
		trans.c[0] += 128 >> trans.state;
	trans.state++;
	if (trans.state >= 8 && (ft_isprint(trans.c[0]) || !trans.c[0]))
	{
		if (!trans.c[0])
		{
			trans.state = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		else
			(ft_putchar_fd(trans.c[0], 1), trans.state = 0);
	}
	kill(info->si_pid, SIGUSR2);
	count++;
}

int	main(void)
{
	struct sigaction	act = {0};

	ft_printf("%d\n", getpid());
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
