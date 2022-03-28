#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	concat_message(t_transmission *t)
{
	if (!t->message)
	{
		t->message = ft_calloc(1, sizeof(char));
		if (!t->message)
			(ft_putstr_fd("Error calloc allocation\n", 1), exit(0));
	}
	t->message = ft_strjoin(t->message, t->c);
}

static void	show_message(t_transmission t, int pid)
{
	ft_printf("\033[32;01mNew message from: %d !\n\033[00m", pid);
	ft_putstr_fd(t.message, 1);
	ft_putchar_fd('\n', 1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
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
			show_message(trans, info->si_pid);
			free(trans.message);
			trans.message = 0;
			trans.state = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		else
			(concat_message(&trans), trans.state = 0);
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("\033[32;01mYou can now send a message to pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" !\033[00m\n", 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
