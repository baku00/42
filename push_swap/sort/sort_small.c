/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:17:50 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 16:46:34 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	*sort_three(int *a, int a_counter)
{
	if (a[0] > a[1] && a[2] && a[2] > a[0])
		a = s(a, a_counter, 'a', 1);
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		a = s(a, a_counter, 'a', 1);
		a = rr(a, a_counter, 'a', 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		a = r(a, a_counter, 'a', 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		a = s(a, a_counter, 'a', 1);
		a = r(a, a_counter, 'a', 1);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		a = rr(a, a_counter, 'a', 1);
	return (a);
}

static t_sort	sort_four(t_sort sort)
{
	
}

void	sort_small(t_sort sort)
{
	if (sort.max_length == 2 && sort.a[0] > sort.a[1])
		sort.a = s(sort.a, 'a', 1);
	else if (sort.max_length == 3)
		sort_three(sort.a, sort.a_counter);
	else if (sort.max_length == 4)
		sort_four(sort.a);
}