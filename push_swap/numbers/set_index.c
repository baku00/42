/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 15:43:42 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_index
{
	int	i;
	int	j;
	int	n;
	int	*sets;
	int	index;
	int	state;
}	t_index;

int	*get_index(int *numbers, int counter)
{
	t_index	index;

	index.i = 0;
	index.state = 1;
	index.sets = ft_calloc(sizeof(int), counter);
	while (index.i < counter)
	{
		index.j = 0;
		index.n = 2147483647;
		while (index.j < counter)
		{
			if (index.n > numbers[index.j] && !index.sets[index.j])
			{
				index.n = numbers[index.j];
				index.index = index.j;
			}
			index.j++;
		}
		index.sets[index.index] = index.state;
		index.state++;
		index.i++;
	}
	return (index.sets);
}
