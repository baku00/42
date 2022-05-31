/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 02:46:51 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	a = a->next;
	tmp->next = a->next;
	a->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

t_element	ra(int *a, int counter)
{
	int	n;
	int	i;
	t_element	element;

	n = a[0];
	i = 0;
	while (i < counter)
	{
		if (a[i + 1])
			a[i] = a[i + 1];
		else
		{
			a[i] = n;
			break;
		}
		i++;
	}
	ft_putstr_fd("ra\n", 1);
	element.a = a;
	return element;
}

t_element	pa(int *a, int *b, int counter)
{
	int	n;
	int	i;
	t_element	element;

	if (!a[0])
	{
		element.a = a;
		element.b = b;
	}
	n = a[0];
	i = 0;
	while (i < counter)
	{
		if (a[i + 1])
			a[i] = a[i + 1];
		else
			a[i] = 0;
		i++;
	}
	i = counter - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = n;
	// ft_putstr_fd("pb\n", 1);
	element.a = b;
	element.b = a;
	return element;
}

t_element	pb(int *a, int *b, int counter)
{
	int	n;
	int	i;
	t_element	element;

	if (!a[0])
	{
		element.a = a;
		element.b = b;
	}
	n = a[0];
	i = 0;
	while (i < counter)
	{
		if (a[i + 1])
			a[i] = a[i + 1];
		else
			a[i] = 0;
		i++;
	}
	i = counter - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = n;
	// ft_putstr_fd("pb\n", 1);
	element.a = a;
	element.b = b;
	return element;
}

void	rra(t_list *a)
{
	t_list	*yet;
	t_list	*tmp;

	yet = (a);
	while (yet->next->next != NULL)
		yet = yet->next;
	tmp = yet->next;
	yet->next = NULL;
	tmp->next = (a);
	(a) = tmp;
	ft_putstr_fd("rra\n", 1);
}
