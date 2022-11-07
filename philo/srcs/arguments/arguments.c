/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:53:19 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 21:50:52 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

static int	valid_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (ft_atoi(argv[i]) <= 0)
			return (0);
	return (1);
}

static int	valid_counter(int argc)
{
	return (argc >= MIN_ARGUMENTS_NUMBER && argc <= MAX_ARGUMENTS_NUMBER);
}

int	check_arguments(int argc, char **argv)
{
	return (valid_arguments(argc, argv) && valid_counter(argc - 1));
}