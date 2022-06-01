/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/06/02 01:46:12 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void show(int *l, char c, int counter, char *end)
// {
// 	int	i;
//
// 	i = 0;
// 	printf("%c: ", c);
// 	while (i < counter)
// 	{
// 		printf("%d ", l[i]);
// 		i++;
// 	}
// 	printf("%s", end);
// }

// t_lists	push_last_bit_one(int *a, int *b, int size, int bit_max, int a_counter, int b_counter)
t_lists	push_last_bit_one(t_lists lst, int size, int bit_max)
{
	t_lists	lists;
	int		i;
	int		nbr;

	lists.a = lst.a;
	lists.b = lst.b;
	lists.a_counter = lst.a_counter;
	lists.b_counter = lst.b_counter;
	i = 0;
	while (i < size)
	{
		nbr = lists.a[0] - 1;
		if (((nbr >> bit_max) & 1) == 0)
		{
			lists = p(lists.a, lists.b, lists.a_counter, lists.b_counter);
			lists.a_counter--;
			lists.b_counter++;
			printf("pb\n");
		}
		else
		{
			lists.a = r(lists.a, lists.a_counter);
			printf("ra\n");
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
		printf("pa\n");
	}
	return lists;
}

// static void	sort_big_stack(int *a, int *b, int counter, int a_counter, int b_counter)
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

int	main(int argc, char **argv)
{
	t_argument	argument;
	t_lists		lists;

	if (!check_number_arguments(argc))
		return (0);
	argument = parse_arguments(argc, argv);
	argument.numbers = convert_to_numbers(argument);
	if (!argument.numbers)
	{
		ft_printf("Error\n");
		return (0);
	}
	lists.a = get_index(argument.numbers, argument.counter);
	lists.b = ft_calloc(sizeof(int), argument.counter);
	lists.b_counter = 1;
	lists.a_counter = argument.counter;
	sort_big_stack(lists, argument.counter);
	return (0);
}
