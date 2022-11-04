/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:56:53 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 15:44:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

typedef struct s_to_string
{
	int		i;
	char	*result;
}	t_to_string;

char	*to_string(char **argv)
{
	t_to_string	to_string;

	to_string.i = -1;
	to_string.result = ft_calloc(sizeof(char), 1);
	if (!to_string.result)
		return (NULL);
	while (argv[++to_string.i])
	{
		to_string.result = ft_strjoin(to_string.result, " ");
		to_string.result = ft_strjoin(to_string);
	}
}