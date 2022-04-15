/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:16:28 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/15 04:56:44 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_null(t_transmission *t)
{
	kill(t->pid, SIGUSR1);
}

static void	send_char(t_transmission *t)
{
	if (!t->c && !t->j)
		t->c = t->message[t->i];
	if (t->j < 8)
	{
		t->move_bytes = 128 >> t->j++;
		t->can_convert = t->c >= t->move_bytes;
		if (t->can_convert)
		{
			t->c -= t->move_bytes;
			kill(t->pid, SIGUSR2);
		}
		else
			kill(t->pid, SIGUSR1);
	}
	if (t->j == 8)
	{
		t->c = 0;
		t->j = 0;
		t->i++;
	}
}

static void	send_msg(char *message, pid_t pid)
{
	static t_transmission	t;

	usleep(35);
	if (!t.message)
	{
		t.message = message;
		t.i = 0;
	}
	if (!t.pid)
	{
		t.pid = pid;
		t.j = 0;
	}
	if (t.message[t.i])
	{
		send_char(&t);
	}
	else
		send_null(&t);
}

void	handler(int signum)
{
	(void) signum;
	if (signum == SIGUSR2)
		send_msg(0, 0);
	else
		(ft_printf("Fin de la transmission\n"), exit(0));
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
	send_msg(transmission.message, transmission.pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
}
