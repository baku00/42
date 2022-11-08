/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 02:02:13 by dgloriod         ###   ########.fr       */
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

typedef struct s_min
{
	int	i;
	int	min;
	int	index;
}	t_min;

static t_min	find_min(int *stack, int counter)
{
	t_min	find;

	find.i = 0;
	find.min = stack[0];
	while (find.i < counter)
	{
		if (find.min > stack[find.i] && stack[find.i] > 0)
		{
			find.min = stack[find.i];
			find.index = find.i;
		}
		find.i++;
	}
	return (find);
}

static t_sort	sort_four(t_sort sort)
{
	int		bingo;
	int		min;

	bingo = 0;
	min = find_min(sort.a, sort.a_counter).min;
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

typedef struct s_five
{
	int	bingo;
	int	min;
}	t_five;

static void	sort_five(t_sort sort)
{
	t_five	five;

	five.bingo = 0;
	if (find_min(sort.a, sort.a_counter).index == sort.a_counter - 1)
		sort.a = rr(sort.a, sort.a_counter - 1, 'a', 1);
	while (five.bingo < 2)
	{
		five.min = find_min(sort.a, sort.a_counter).min;
		if (sort.a[0] == five.min)
		{
			sort = pb(sort);
			five.bingo++;
		}
		else if (sort.a[1] == five.min)
		{
			sort.a = s(sort.a, 'a', 1);
			sort = pb(sort);
			five.bingo++;
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
		sort_four(sort);
	else if (sort.a_counter == 5)
		sort_five(sort);
}
