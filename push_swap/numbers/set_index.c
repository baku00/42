/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/10/30 20:19:02 by dgloriod         ###   ########.fr       */
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
	int	*exists;
	int	state;
}	t_index;

static bool	exists(int *numbers, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < counter)
	{
		j = 0;
		while (j < counter)
		{
			if (i != j && numbers[i] == numbers[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	*get_index(int *numbers, int counter)
{
	t_index	index;

	index.i = -1;
	index.state = 1;
	index.sets = ft_calloc(sizeof(int), counter);
	index.exists = ft_calloc(sizeof(int), counter);
	while (++(index.i) < counter)
	{
		index.j = 0;
		index.n = 2147483647;
		while (index.j < counter)
		{
			if (index.n >= numbers[index.j] && !index.sets[index.j])
			{
				index.n = numbers[index.j];
				if (exists(numbers, counter))
					return (NULL);
				index.index = index.j;
			}
			index.j++;
		}
		index.sets[index.index] = index.state++;
	}
	free(index.exists);
	return (index.sets);
}
