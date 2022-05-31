/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 01:49:14 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_index
{
	int	*index;
	int	n;
	int	i;
	int	j;
	int	tmp;
}	t_index;

static bool	exist(int *numbers, int n, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (numbers[i] == n)
			return true;
		i++;
	}
	return false;
}

int	*get_index(int *numbers, int counter)
{
	t_index	index;

	index.index = ft_calloc(sizeof(int), counter + 1);
	if (!index.index)
		return (NULL);
	index.i = -1;
	while (++(index.i) < counter)
	{
		index.n = 2147483647;
		index.j = -1;
		index.tmp = 0;
		while (++(index.j) < counter) {
			if (index.n > numbers[index.j] && !exist(index.index, index.j + 1, counter))
			{
				index.n = numbers[index.j];
				index.tmp = (index.j + 1);
			}
		}
		index.index[index.i] = index.tmp;
	}
	// index.i = -1;
	// while (++(index.i) < counter)
	// 	index.index[index.i] -= 1;
	return (index.index);
}
