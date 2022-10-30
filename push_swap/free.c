/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:10:53 by user              #+#    #+#             */
/*   Updated: 2022/10/30 23:03:47 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freeall(t_argument argument, t_lists lists)
{
	int i;

	i = -1;
	free(argument.numbers);
	free(argument.arg);
	while (++i < argument.counter)
		free(argument.args[i]);
	free(argument.args);
	free(lists.a);
	free(lists.b);
}