/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 02:45:43 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	empty_b(int *a, int *b, int counter)
{
	int	i;
	t_element	element;
	t_element	tmp;
	element.a = a;
	element.b = b;
	i = 0;
	while (i < counter)
	{
		ft_printf("B[%d]: %d\n\n", i, b[i]);
		tmp = pa(element.b, element.a, counter);
		element.a = tmp.b;
		element.b = tmp.a;
		// if (1 == 1)
		{
			int x = 0;
			while (x < counter)
			ft_printf("%d\n", element.b[x++]);
			ft_printf("\n");
			x = 0;
			while (x < counter)
			ft_printf("%d\n", element.a[x++]);
			ft_printf("\n");
		}
		i++;
		ft_printf("pa\n");
	}
	return element;
}

t_element	push_last_bit_one(int *a, int *b, int size, int bit_max, int counter)
{
	int		i;
	int		nbr;
	t_element	element;
	(void) counter;

	i = 0;
	element.a = a;
	element.b = b;
	while (i < size)
	{
		nbr = (element.a[i] - 1);
		if (nbr >= 0)
		{
			if (((nbr >> bit_max) & 1) == 0)
			{
				element = pb(element.a, element.b, counter);
			}
			else
			{
				element.a = ra(element.a, counter).a;
			}
		}
		ft_printf("CHECK\n");
		i++;
	}
	return element;
}

t_element	sort_big_stack(int *a, int counter)
{
	int		*b;
	int		size;
	int		max_num;
	int		bit_max;
	t_element	element;

	b = ft_calloc(sizeof(int), counter + 1);
	size = counter;
	max_num = size - 1;
	bit_max = 0;
	(void) bit_max;
	(void) max_num;
	element.a = a;
	element.b = b;
	// sort_list(a);
	// while (max_num >> bit_max != 0)
	{
		element = push_last_bit_one(element.a, element.b, size, bit_max, counter);
		element = empty_b(element.a, element.b, counter);
		// break;
		bit_max++;
	}
	return element;
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	t_argument	argument;
	int			*index;

	if (!check_number_arguments(argc))
		return (0);
	argument = parse_arguments(argc, argv);
	argument.numbers = convert_to_numbers(argument);
	if (!argument.numbers)
	{
		ft_printf("Error\n");
		return (0);
	}
	index = get_index(argument.numbers, argument.counter);
	// int i = 0;
	// while (i < argument.counter)
	// {
	// 	ft_printf("Index[%d]: %d\n", i, index[i]);
	// 	i++;
	// }
	// int i = 0;
	// while (i < argument.counter) {
	// 	ft_printf("%d\n", index[i++]);
	// }
	// ft_printf("\n");
	// push_swap.a = ft_save(argument.numbers, argument.counter, index);
	// while (push_swap.a) {
	// 	ft_printf("%d | %d\n", push_swap.a->nbr, push_swap.a->index);
	// 	push_swap.a = push_swap.a->next;
	// }
	push_swap.a = sort_big_stack(index, argument.counter).a;
	(void) push_swap;
	// i = 0;
	// while (i < argument.counter)
	// {
	// 	ft_printf("%d\n", push_swap.a[i]);
	// 	i++;
	// }
	return (0);
}
