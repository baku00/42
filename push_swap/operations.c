/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 01:41:40 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*r(int *l, int counter)
{
	int	n;
	int	i;

	n = l[0];
	i = 0;
	while (i < counter - 1)
	{
		if (l[i + 1])
			l[i] = l[i + 1];
		i++;
	}
	l[i] = n;
	return (l);
}

int	*rr(int *l, int counter)
{
	int	n;
	int	i;

	n = l[counter - 1];
	i = counter - 1;
	while (i > 0)
	{
		if (l[i - 1])
			l[i] = l[i - 1];
		i--;
	}
	l[i] = n;
	return (l);
}

t_lists	p(int *l1, int *l2, int counter1, int counter2)
{
	t_lists	lists;
	int		n;

	n = l1[0];
	l1 = r(l1, counter1);
	l1[counter1 - 1] = 0;
	l2[counter2 - 1] = n;
	l2 = rr(l2, counter2);
	lists.a = l1;
	lists.b = l2;
	lists.a_counter = counter1;
	lists.b_counter = counter2;
	return (lists);
}
