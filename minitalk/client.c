/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:10:04 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/15 05:14:14 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
