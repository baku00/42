#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	static int				count;
	static t_transmission	transmission;

	if (!transmission.state)
	{
		transmission.c[0] = 0;
	}
	if (signum == SIGUSR2)
		transmission.c[0] += 128 >> transmission.state;
	transmission.state++;
	if (transmission.state >= 8 && (ft_isprint(transmission.c[0]) || !transmission.c[0]))
	{
		if (!transmission.c[0])
		{
			transmission.state = 0;
			kill(info->si_pid, SIGUSR1);
			return;
		}else{
			ft_putchar_fd(transmission.c[0], 1);
			transmission.state = 0;
		}
	}
	(void) context;
	(void) signum;
	kill(info->si_pid, SIGUSR2);
	count++;
}

int main(void)
{
	printf("%d\n", getpid());
	struct sigaction act = { 0 };
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	(void) act;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1) {
		pause();
	}
}
