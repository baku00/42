/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:10:53 by user              #+#    #+#             */
/*   Updated: 2022/10/31 17:07:39 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void freeall(t_argument argument, t_lists lists)
{
	printf("FREE ALL\n");
	printf("Number: %ld\n", malloc_usable_size(argument.numbers));
	free(argument.numbers);
	printf("Number: %ld\n", malloc_usable_size(argument.numbers));
	printf("Arg: %ld\n", malloc_usable_size(argument.arg));
	free(argument.arg);
	free(argument.args);
	free(lists.a);
	free(lists.b);
	printf("Size: %ld\n", malloc_usable_size(argument.arg));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:10:53 by user              #+#    #+#             */
/*   Updated: 2022/10/30 23:28:10 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freeall(t_argument argument, t_lists lists)
{
	int i;

	free(argument.numbers);
	free(argument.arg);
	i = -1;
	while (++i < argument.counter)
		free(argument.args[i]);
	free(argument.args);
	free(lists.a);
	free(lists.b);
}
