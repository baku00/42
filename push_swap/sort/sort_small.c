/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 00:59:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_sort	sort_three(int *a, int a_counter)
{
	t_sort	sort;

	if (a[0] > a[1] && a[2] && a[2] > a[0])
		a = s(a, 'a', 1);
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		a = s(a, 'a', 1);
		a = rr(a, a_counter, 'a', 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		a = r(a, a_counter, 'a', 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		a = s(a, 'a', 1);
		a = r(a, a_counter, 'a', 1);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		a = rr(a, a_counter, 'a', 1);
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

static t_sort	sort_four(t_sort sort)
{
	int		bingo;
	int		min;

	bingo = 0;
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
			sort.a = s(sort.a, 'a', 1);
			sort = pb(sort);
			bingo++;
		}
		else
			sort.a = r(sort.a, sort.a_counter, 'a', 1);
	}
	sort_three(sort.a, sort.a_counter);
	sort = pa(sort);
	return (sort);
}

static void	sort_five(t_sort sort)
{
	t_sort	reverse;
	int		bingo;
	int		min;

	bingo = 0;
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
			sort.a = s(sort.a, 'a', 1);
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
	if (sort.a_counter == 2 && sort.a[0] > sort.a[1])
		sort.a = s(sort.a, 'a', 1);
	else if (sort.a_counter == 3)
		sort_three(sort.a, sort.a_counter);
	else if (sort.a_counter == 4)
		sort_four(sort.a, sort.b, sort.a_counter, sort.b_counter);
	else if (sort.a_counter == 5)
		sort_five(sort.a, sort.b, sort.a_counter, sort.b_counter);
}
