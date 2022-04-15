/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:16:34 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/15 04:34:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include "./includes/ft_printf/ft_printf.h"

typedef struct s_transmission
{
	size_t	i;
	size_t	j;
	int		pid;
	int		send_null;
	char	*message;
	char	*signals_temp;
	size_t	length_loop;
	size_t	length;
	int		state;
	char	c;
	int		move_bytes;
	int		can_convert;
}	t_transmission;

typedef struct s_int_to_binary
{
	int		i;
	int		from;
	int		move_bytes;
	int		can_convert;
	char	*result;
}	t_int_to_binary;

void	send_message(char *message, int pid);

#endif
