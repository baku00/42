/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 17:35:52 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_sort	sort_three(int *a, int a_counter)
{
	t_sort	sort;

	if (a[0] > a[1] && a[2] && a[2] > a[0])
		(ft_printf("sa\n"), a = sa(a));
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		(ft_printf("sa\n"), a = sa(a));
		a = rr(a, a_counter, 'a', 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		a = r(a, a_counter, 'a', 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		(ft_printf("sa\n"), a = sa(a));
		a = r(a, a_counter, 'a', 1);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		a = rr(a, a_counter, 'a', 1);
	}
	sort.a = a;
	return (sort);
}

static int	find_min(int *stack, int counter)
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

static t_sort	sort_four(int *a, int *b, int a_counter, int b_counter)
{
	int		bingo;
	int		min;
	t_sort	sort;
	t_sort	reverse;

	bingo = 0;
	sort.a = a;
	sort.b = b;
	sort.a_counter = a_counter;
	sort.b_counter = b_counter;
	min = find_min(sort.a, sort.a_counter);
	while (!bingo)
	{
		if (sort.a[0] == min)
		{
			sort = pb(sort);
			bingo++;
		}
		else if (sort.a[1] == min)
		{
			sort.a = sa(sort.a);
			ft_printf("sa\n");
			sort = pb(sort);
			bingo++;
		}
		else
		{
			sort.a = r(sort.a, sort.a_counter, 'a', 1);
		}
	}
	sort_three(sort.a, sort.a_counter);
	sort = pa(sort);
	return (sort);
}

static void	sort_five(int *a, int *b, int a_counter, int b_counter)
{
	t_sort	sort;
	t_sort	reverse;
	int		bingo;
	int		min;

	bingo = 0;
	sort.a = a;
	sort.b = b;
	sort.a_counter = a_counter;
	sort.b_counter = b_counter;
	while (bingo < 2)
	{
		min = find_min(sort.a, sort.a_counter);
		if (a[0] == min)
		{
			sort = pb(sort);
			bingo++;
		}
		else if (a[1] == min)
		{
			sort.a = sa(a);
			ft_printf("sa\n");
			sort = pb(sort);
			bingo++;
		}
		else
			sort.a = r(sort.a, sort.a_counter, 'a', 1);
	}
	sort_three(sort.a, sort.a_counter);
	sort = pa(sort);
	sort = pa(sort);
}

void	sort_small(t_sort sort)
{
	if (sort.a_counter == 2)
	{
		if (sort.a[0] > sort.a[1])
		{
			sa(sort.a);
			ft_printf("sa\n");
		}
	}
	else if (sort.a_counter == 3)
		sort_three(sort.a, sort.a_counter);
	else if (sort.a_counter == 4)
		sort_four(sort.a, sort.b, sort.a_counter, sort.b_counter);
	else if (sort.a_counter == 5)
		sort_five(sort.a, sort.b, sort.a_counter, sort.b_counter);
}