/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:09:59 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/24 20:17:01 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	finish(t_transmission *t)
{
	ft_printf("\n");
	t->state = 0;
	kill(t->pid, SIGUSR1);
	t->pid = 0;
	t->c = 0;
}

void	handler(int sig, siginfo_t *info, __attribute__((unused)) void *ctx)
{
	static t_transmission	t;

	if (!t.pid && info->si_pid)
	{
		t.pid = info->si_pid;
		ft_printf("\033[32;01mMessage from: %d !\n\033[00m", t.pid);
		t.state = 1;
	}
	if (t.pid == info->si_pid && info->si_pid)
	{
		if (t.state == 1)
			t.c = 0;
		if (sig == SIGUSR2)
			t.c += 128 >> (8 - t.state);
		usleep(50);
		t.state++;
		if (t.state == 9 && (ft_isprint(t.c) || !t.c))
		{
			if (!t.c)
				return (finish(&t));
			else
				(ft_printf("%c", t.c), t.state = 1);
		}
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("\033[32;01mYou can now send a message to pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" !\033[00m\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
