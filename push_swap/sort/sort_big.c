/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:05:49 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 17:00:50 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

typedef struct s_big
{
	int	b;
	int	i;
	int	max;
	int	counter;
}	t_big;

void	sort_big(t_sort sort)
{
	t_big	big;
	t_sort	reverse;

	big.b = 1;
	while (big.b < sort.max_length)
	{
		big.i = -1;
		while (++big.i < sort.max_length)
		{
			if (sort.a[0] & big.b)
				sort.a = r(sort.a, sort.a_counter, 'a', 1);
			else
				sort = pb(sort);
		}
		big.i = -1;
		big.counter = sort.b_counter;
		while (++big.i < big.counter)
			sort = pa(sort);
		big.b *= 2;
	}
}
