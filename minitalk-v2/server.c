/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:16:08 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/15 04:56:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	check_char(t_transmission *t)
{
	if (t->state >= 8 && (ft_isprint(t->c) || !t->c))
	{
		if (!t->c)
		{
			(ft_printf("\n\n"), t->state = 0);
			ft_printf("\033[32;01mServer pid: %d !\033[00m\n", getpid());
			kill(t->pid, SIGUSR1);
			t->pid = 0;
			return ;
		}
		else
			(ft_printf("%c", t->c), t->state = 0);
	}
	kill(t->pid, SIGUSR2);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static t_transmission	t;

	((void) context, (void) signum);
	if (!t.state)
		t.c = 0;
	if (signum == SIGUSR2)
		t.c += 128 >> t.state;
	if (!t.pid && info->si_pid)
		(ft_printf("\033[32;01mMessage from: %d !\033[00m\n", info->si_pid), \
		t.pid = info->si_pid);
	if (t.pid == info->si_pid)
	{
		t.state++;
		usleep(35);
		check_char(&t);
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
