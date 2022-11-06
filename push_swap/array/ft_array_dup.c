/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:56:53 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/06 16:07:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

typedef struct s_array_dup
{
	int		length;
	int		i;
	char	**array;
}	t_array_dup;

char	**ft_array_dup(char **argv)
{
	t_array_dup	array_dup;

	array_dup.length = ft_array_length(argv);
	array_dup.i = -1;
	array_dup.array = ft_calloc(sizeof(char *), array_dup.length + 1);
	if (!array_dup.array)
		return (NULL);
	while (++array_dup.i < array_dup.length)
	{
		free(array_dup.array[array_dup.i]);
		array_dup.array[array_dup.i] = ft_strdup(argv[array_dup.i]);
		if (!array_dup.array[array_dup.i])
		{
			free_array(array_dup.array, array_dup.i);
			return (NULL);
		}
	}
	return (array_dup.array);
}

typedef struct s_int_array
{
	int	i;
	int	*array;
}	t_int_array;

int	*ft_int_array_dup(int *array, int length)
{
	t_int_array	int_array;

	int_array.array = ft_calloc(sizeof(int), length);
	if (!int_array.array)
		return (NULL);
	int_array.i = -1;
	while (++int_array.i < length)
		int_array.array[int_array.i] = array[int_array.i];
	return (int_array.array);
}
