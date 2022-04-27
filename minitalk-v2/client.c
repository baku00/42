/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:10:04 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/27 04:21:05 by dgloriod         ###   ########.fr       */
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

100 =>					0	1	1	0	0	1	0	0
50 =>					0	0	1	1	0	0	1	0
10 =>					0	0	0	0	1	0	1	0
*/

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

	if (!trans.pid)
	{
		trans.message = ft_strdup(message);
		trans.i = 0;
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

// (void) argc;
// (void) argv;
//
// char c = '1';
// for (int i = 0; i < 8; i++)
// printf("C: %d => %d => %d => %d\n", c, i, c >> i, c >> i & 100); => voir table au dessus
// return (0);
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
