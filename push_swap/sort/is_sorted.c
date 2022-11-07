/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:16:45 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 02:01:58 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

typedef struct s_sorted
{
	int	i;
}	t_sorted;

int	is_sorted(t_sort sort)
{
	t_sorted	sorted;

	sorted.i = -1;
	while (++sorted.i < sort.max_length -1)
		if (sort.a[sorted.i] + 1 != sort.a[sorted.i + 1])
			return (0);
	return (1);
}
