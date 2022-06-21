/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:53:19 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/21 02:02:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int	check_arguments_type(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
	}
}

int	check_arguments_number(int argc)
{
	return (argc >= MIN_ARGUMENTS_NUMBER && argc <= MAX_ARGUMENTS_NUMBER);
}

int	check_arguments(int argc, char **argv)
{
	if (!check_arguments_number(argc))
		return (false);
}