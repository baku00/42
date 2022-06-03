/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/03 03:19:31 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	more_int(char *n)
{
	int		i;
	char	*limit;

	limit = "2147483647";
	if (n[0] == '-')
		return (false);
	if (ft_strlen(n) > 10)
		return (true);
	else if (ft_strlen(n) == 10)
	{
		i = -1;
		while (limit[++i])
		{
			if (n[i] > limit[i])
				return (true);
		}
	}
	return (false);
}

static bool	less_int(char *n)
{
	int		i;
	char	*limit;

	limit = "-2147483648";
	if (n[0] != '-')
		return (false);
	if (ft_strlen(n) > 11)
		return (true);
	else if (ft_strlen(n) == 11)
	{
		i = 0;
		while (limit[++i])
		{
			if (n[i] > limit[i])
				return (true);
		}
	}
	return (false);
}

int	*convert_to_numbers(t_argument argument)
{
	int	*numbers;
	int	i;
	int	j;
	int	got_digit;

	numbers = ft_calloc(sizeof(int), argument.counter);
	if (!numbers)
		return (NULL);
	i = -1;
	while (++i < argument.counter)
	{
		j = -1;
		got_digit = 0;
		while (argument.args[i][++j])
		{
			if (!ft_isdigit(argument.args[i][j]) && argument.args[i][j] != '-')
				return (NULL);
			else if (ft_isdigit(argument.args[i][j]) && j <= 1)
				got_digit = 1;
		}
		if (!got_digit || more_int(argument.args[i]) || less_int(argument.args[i]))
			return (NULL);
		numbers[i] = ft_atoi(argument.args[i]);
	}
	return (numbers);
}
