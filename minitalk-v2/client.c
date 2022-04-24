/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:10:04 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/24 20:27:56 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_null(t_transmission *t)
{
	static int	i;

	if (i < 8)
		kill(t->pid, SIGUSR1);
	else
	{
		t->pid = 0;
		free(t->message);
		t->message = NULL;
		t->i = 0;
		t->j = 0;
		exit(0);
	}
	i++;
}

void	send_message(char *message, int pid)
{
	static t_transmission	trans;

	if (!trans.message)
	{
		trans.message = ft_strdup(message);
		trans.i = 0;
	}
	if (!trans.pid)
	{
		trans.pid = pid;
		trans.j = 0;
	}
	usleep(50);
	if (trans.message[trans.i])
	{
		if (trans.message[trans.i] >> trans.j & 1)
			kill(trans.pid, SIGUSR2);
		else
			kill(trans.pid, SIGUSR1);
		if (trans.j == 7)
			trans.i++;
		trans.j = (trans.j + 1) % 8;
	}
	else
		send_null(&trans);
}

void	handler(int signum)
{
	(void) signum;
	if (signum == SIGUSR2)
		send_message(0, 0);
	else
		(ft_putstr_fd("Fin de la transmission\n", 1), exit(0));
}

int	main(int argc, char **argv)
{
	t_transmission	transmission;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <server pid> <message>\n");
		return (0);
	}
	transmission.pid = ft_atoi(argv[1]);
	transmission.message = argv[2];
	send_message(transmission.message, transmission.pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
}
