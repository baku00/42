/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/03 12:55:28 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void show(int *l, char c, int counter, char *end)
// {
// 	int	i;
//
// 	i = 0;
// 	ft_printf("%c: ", c);
// 	while (i < counter)
// 	{
// 		ft_printf("%d ", l[i]);
// 		i++;
// 	}
// 	ft_printf("%s", end);
// }

t_lists	push_last_bit_one(t_lists lst, int size, int bit_max)
{
	t_lists	lists;
	int		i;

	lists.a = lst.a;
	lists.b = lst.b;
	lists.a_counter = lst.a_counter;
	lists.b_counter = lst.b_counter;
	i = 0;
	while (i < size)
	{
		if ((((lists.a[0] - 1) >> bit_max) & 1) == 0)
		{
			lists = p(lists.a, lists.b, lists.a_counter, lists.b_counter);
			lists.a_counter--;
			lists.b_counter++;
			ft_printf("pb\n");
		}
		else
		{
			lists.a = r(lists.a, lists.a_counter);
			ft_printf("ra\n");
		}
		i++;
	}
	return (lists);
}

static t_lists	empty_b(int *a, int *b, int a_counter, int b_counter)
{
	t_lists	lists;
	t_lists	reverse;

	lists.a = a;
	lists.b = b;
	lists.a_counter = a_counter;
	lists.b_counter = b_counter;
	while (lists.b_counter > 1)
	{
		lists.a_counter++;
		lists.b_counter--;
		reverse = p(lists.b, lists.a, lists.b_counter, lists.a_counter);
		lists.a = reverse.b;
		lists.b = reverse.a;
		ft_printf("pa\n");
	}
	return (lists);
}

static void	sort_big_stack(t_lists lst, int counter)
{
	int		size;
	int		max_num;
	int		bit_max;
	t_lists	lists;

	size = counter;
	max_num = size - 1;
	bit_max = 0;
	lists.a = lst.a;
	lists.b = lst.b;
	lists.a_counter = lst.a_counter;
	lists.b_counter = lst.b_counter;
	while (max_num >> bit_max != 0)
	{
		lists = push_last_bit_one(lists, size, bit_max);
		lists = empty_b(lists.a, lists.b, lists.a_counter, lists.b_counter);
		bit_max++;
	}
}

static int	error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_argument	argument;
	t_lists		lists;

	if (!check_number_arguments(argc))
		return (0);
	argument = parse_arguments(argc, argv);
	argument.numbers = convert_to_numbers(argument);
	if (!argument.numbers)
		return (error());
	lists.a = get_index(argument.numbers, argument.counter);
	if (!lists.a)
		return (0);
	lists.b = ft_calloc(sizeof(int), argument.counter);
	if (!lists.b)
		return (0);
	lists.b_counter = 1;
	lists.a_counter = argument.counter;
	if (is_sorted(lists.a, lists.a_counter))
		return (freeall(argument, lists, 1));
	if (argument.counter <= 5)
		sort_small_stack(lists);
	else
		sort_big_stack(lists, argument.counter);
	return (freeall(argument, lists, 1));
}
