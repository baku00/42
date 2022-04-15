/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:10:14 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/15 05:10:15 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*i_t_b(int c)
{
	t_int_to_binary	itb;

	itb.i = 0;
	itb.from = 128;
	itb.can_convert = 0;
	itb.result = ft_calloc(9, sizeof(char));
	if (!itb.result)
		return (0);
	while (itb.i < 8)
	{
		itb.move_bytes = itb.from >> itb.i;
		itb.can_convert = c >= itb.move_bytes;
		itb.result[itb.i] = itb.can_convert + 48;
		if (itb.can_convert)
			c -= itb.move_bytes;
		itb.i++;
	}
	return (itb.result);
}

static void	send_null(int pid)
{
	static int	i;

	if (i < 8)
		kill(pid, SIGUSR1);
	else
		exit(0);
	i++;
}

static void	reset_var(t_transmission *trans)
{
	if (trans->signals_temp && !trans->signals_temp[trans->j])
	{
		(free(trans->signals_temp), trans->j = 0);
		trans->signals_temp = 0;
	}
	if (!trans->message[trans->i])
		(free(trans->message), trans->send_null = 1);
	else
	{
		trans->signals_temp = i_t_b(trans->message[trans->i]);
		trans->i++;
	}
}

void	send_message(char *message, int pid)
{
	static t_transmission	trans;

	if (!trans.message)
		trans.message = ft_strdup(message);
	if (!trans.pid)
		trans.pid = pid;
	usleep(50);
	if (!trans.send_null)
	{
		if (!trans.signals_temp || !trans.signals_temp[trans.j])
			reset_var(&trans);
		if (trans.signals_temp)
		{
			if (trans.signals_temp[trans.j] - 48)
				(kill(trans.pid, SIGUSR2), trans.j++);
			else
				(kill(trans.pid, SIGUSR1), trans.j++);
		}
	}
	if (!trans.signals_temp)
		send_null(trans.pid);
}
