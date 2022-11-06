/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:23:47 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 17:00:32 by dgloriod         ###   ########.fr       */
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

	if (!counter)
		return (l);
	n = l[0];
	i = -1;
	while (++i < counter - 1)
		l[i] = l[i + 1];
	l[i] = n;
	if (display)
		ft_printf("r%c\n", c);
	return (l);
}

int	*rr(int *l, int counter, char c, int display)
{
	int	n;
	int	i;

	if (!counter)
		return (l);
	n = l[counter];
	i = counter + 1;
	while (--i > 0)
		l[i] = l[i - 1];
	l[0] = n;
	if (display)
		ft_printf("rr%c\n", c);
	return (l);
}

t_sort	pb(t_sort sort)
{
	t_sort	lists;
	int		n;
	int		show;

	n = sort.a[0];
	sort.a = r(sort.a, sort.a_counter, ' ', 0);
	sort.a_counter -= 1;
	sort.a[sort.a_counter] = 0;
	sort.b[sort.b_counter] = n;
	sort.b = rr(sort.b, sort.b_counter, ' ', 0);
	sort.b_counter += 1;
	lists.a = sort.a;
	lists.b = sort.b;
	lists.a_counter = sort.a_counter;
	lists.b_counter = sort.b_counter;
	lists.max_length = sort.max_length;
	ft_printf("pb\n");
	return (lists);
}

t_sort	pa(t_sort sort)
{
	t_sort	lists;
	int		n;

	n = sort.b[0];
	sort.b = r(sort.b, sort.b_counter, ' ', 0);
	sort.b_counter -= 1;
	sort.b[sort.b_counter] = 0;
	sort.a[sort.a_counter] = n;
	sort.a = rr(sort.a, sort.a_counter, ' ', 0);
	sort.a_counter += 1;
	lists.b = sort.b;
	lists.a = sort.a;
	lists.b_counter = sort.b_counter;
	lists.a_counter = sort.a_counter;
	lists.max_length = sort.max_length;
	ft_printf("pa\n");
	return (lists);
}
