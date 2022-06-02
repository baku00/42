/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 16:05:37 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_lists	sort_three(int *a, int a_counter)
{
	t_lists	lists;

	if (a[0] > a[1] && a[2] && a[2] > a[0])
		(ft_printf("sa\n"), a = sa(a));
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		(ft_printf("sa\n"), a = sa(a));
		a = rr(a, a_counter);
		ft_printf("rra\n");
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		(ft_printf("ra\n"), a = r(a, a_counter));
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		(ft_printf("sa\n"), a = sa(a));
		a = r(a, a_counter);
		ft_printf("ra\n");
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		a = rr(a, a_counter);
		ft_printf("rra\n");
	}
	lists.a = a;
	return (lists);
}

static t_lists	make_five(t_lists lists, int i, int min, int min_on_start)
{
	while ((!min_on_start && i < 2) || (min_on_start && !i))
	{
		if (!min_on_start)
			min = find_min(lists.a, lists.a_counter);
		if (lists.a[0] == min)
		{
			lists = p(lists.a, lists.b, lists.a_counter, lists.b_counter);
			ft_printf("pb\n");
			lists.a_counter--;
			lists.b_counter++;
			i++;
		}
		else if (lists.a[1] == min)
		{
			(ft_printf("sa\n"), lists.a = sa(lists.a));
			lists = p(lists.a, lists.b, lists.a_counter, lists.b_counter);
			ft_printf("pb\n");
			lists.a_counter--;
			lists.b_counter++;
			i++;
		}
		else
			(ft_printf("ra\n"), lists.a = r(lists.a, lists.a_counter));
	}
	return (lists);
}

static t_lists	sort_four(int *a, int *b, int a_counter, int b_counter)
{
	t_lists	lists;
	t_lists	reverse;

	lists.a = a;
	lists.b = b;
	lists.a_counter = a_counter;
	lists.b_counter = b_counter;
	make_five(lists, 0, 0, find_min(lists.a, lists.a_counter));
	sort_three(lists.a, lists.a_counter);
	lists.a_counter++;
	lists.b_counter--;
	reverse = p(lists.b, lists.a, lists.b_counter, lists.a_counter);
	ft_printf("pa\n");
	lists.a = reverse.b;
	lists.b = reverse.a;
	return (lists);
}

static void	sort_five(int *a, int *b, int a_counter, int b_counter)
{
	t_lists	lists;
	t_lists	reverse;

	lists.a = a;
	lists.b = b;
	lists.a_counter = a_counter;
	lists.b_counter = b_counter;
	make_five(lists, 0, 0, 0);
	sort_three(lists.a, lists.a_counter);
	lists.a_counter++;
	lists.b_counter--;
	reverse = p(lists.b, lists.a, lists.b_counter, lists.a_counter);
	lists.a = reverse.b;
	lists.b = reverse.a;
	ft_printf("pa\n");
	lists.a_counter++;
	lists.b_counter--;
	reverse = p(lists.b, lists.a, lists.b_counter, lists.a_counter);
	lists.a = reverse.b;
	lists.b = reverse.a;
	ft_printf("pa\n");
}

void	sort_small_stack(t_lists lists)
{
	if (lists.a_counter == 2)
	{
		if (lists.a[0] > lists.a[1])
		{
			sa(lists.a);
			ft_printf("sa\n");
		}
	}
	else if (lists.a_counter == 3)
		sort_three(lists.a, lists.a_counter);
	else if (lists.a_counter == 4)
		sort_four(lists.a, lists.b, lists.a_counter, lists.b_counter);
	else if (lists.a_counter == 5)
		sort_five(lists.a, lists.b, lists.a_counter, lists.b_counter);
}
