/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 01:32:06 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*convert_to_numbers(t_argument argument)
{
	int	*numbers;
	int	i;
	int	j;

	numbers = ft_calloc(sizeof(int), argument.counter);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < argument.counter)
	{
		j = 0;
		while (argument.args[i][j])
		{
			if (!ft_isdigit(argument.args[i][j]))
				return (NULL);
			j++;
		}
		numbers[i] = ft_atoi(argument.args[i]);
		i++;
	}
	return (numbers);
}
