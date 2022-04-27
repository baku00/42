/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:09:59 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/27 04:11:30 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
						128	64	32	16	8	4	2	1
0 => 48 =>				0	0	1	1	0	0	0	0

48 >> 0 => 48 =>		0	0	1	1	0	0	0	0
48 >> 1 = 24 =>			0	0	0	1	1	0	0	0
48 >> 2 = 12 =>			0	0	0	0	1	1	0	0
48 >> 3 = 6 =>			0	0	0	0	0	1	1	0
48 >> 4 = 3 =>			1	1	0	0	0	0	1	1
48 >> 5 = 1 =>			0	0	0	0	0	0	0	1
48 >> 6 = 0 =>			0	0	0	0	0	0	0	0
48 >> 7 = 0 =>			0	0	0	0	0	0	0	0

1 => 49 => 				0	0	1	1	0	0	0	1

49 >> 0 = 49 =>			0	0	1	1	0	0	0	1
49 >> 1 = 24 =>			0	0	0	1	1	0	0	0
49 >> 2 = 12 =>			0	0	0	0	1	1	0	0
49 >> 3 = 6 =>			0	0	0	0	0	1	1	0
49 >> 4 = 3 =>			1	1	0	0	0	0	1	1
49 >> 5 = 1 =>			0	0	0	0	0	0	0	1
49 >> 6 = 0 =>			0	0	0	0	0	0	0	0
49 >> 7 = 0 =>			0	0	0	0	0	0	0	0

49 >> 0 & 1 => 0b1		0	0	0	0	0	0	0	?1
49 >> 1 & 1 => 0b100	0	0	0	0	0	?0	0	0
49 >> 2 & 1 => 0b100	0	0	0	0	0	?1	0	0
*/

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	show_pid()
{
	ft_putstr_fd("\033[32;01mYou can now send a message to pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" !\033[00m\n", 1);
}

static void	finish(t_transmission *t)
{
	ft_printf("\n");
	ft_printf("\033[32;01mCommunication with %d, terminate!\n\033[00m", t->pid);
	ft_printf("\n");
	show_pid();
	kill(t->pid, SIGUSR1);
	t->state = 0;
	t->pid = 0;
	t->c = 0;
}

void	handler(int sig, siginfo_t *info, __attribute__((unused)) void *ctx)
{
	static t_transmission	t;

	if (!t.pid && info->si_pid)
	{
		t.pid = info->si_pid;
		t.state = 7;
		ft_printf("\033[32;01mMessage from: %d !\n\033[00m", t.pid);
	}
	if (t.pid == info->si_pid && info->si_pid)
	{
		if (t.state == 7)
			t.c = 0;
		if (sig == SIGUSR2)
			t.c += 128 >> t.state;
		usleep(50);
		t.state--;
		if (t.state == -1)
		{
			if (!t.c)
				return (finish(&t));
			else
				(ft_printf("%c", t.c), t.state = 7);
		}
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	act;

	show_pid();
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
