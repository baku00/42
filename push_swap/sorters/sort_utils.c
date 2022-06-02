/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 19:38:41 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(int *stack, int counter)
{
	int	i;
	int	min;

	i = 0;
	min = stack[0];
	while (i < counter)
	{
		if (min > stack[i] && stack[i] > 0)
			min = stack[i];
		i++;
	}
	return (min);
}

bool	is_sorted(int *numbers, int counter)
{
	int	i;
	int	n;

	i = 1;
	n = numbers[0];
	while (i < counter)
	{
		if (n + 1 != numbers[i])
			return (false);
		n = numbers[i];
		i++;
	}
	return (true);
}
