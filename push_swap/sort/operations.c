/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:23:47 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 16:41:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	*s(int *list, char c, int display)
{
	int	temp;

	temp = list[0];
	list[0] = list[1];
	list[1] = temp;
	if (display)
		ft_printf("s%c\n", c);
	return (list);
}

int	*r(int *l, int counter, char c, int display)
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
	if (display)
		ft_printf("r%c\n", c);
	return (l);
}

int	*rr(int *l, int counter, char c, int display)
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
	if (display)
		ft_printf("r%c\n", c);
	return (l);
}

t_sort	p(int *l1, int *l2, int counter1, int counter2)
{
	t_sort	lists;
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
