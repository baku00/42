/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:15:53 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/08 00:31:21 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

static int	valid_arg(t_format format)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	if (!str)
		return (-1);
	str[0] = '+';
	str = ft_strjoin(str, format.itoa);
	if (!str)
		return (-1);
	if (ft_strncmp(format.args[format.i], format.itoa, format.strlen) && \
		ft_strncmp(format.args[format.i], str, format.strlen))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

t_format	check_format_utils(t_format format)
{
	format.i = -1;
	format.error = 0;
	while (!format.error && ++format.i < format.length)
	{
		format.atoi = ft_atoi(format.args[format.i]);
		format.itoa = ft_itoa(format.atoi);
		format.strlen = ft_strlen(format.args[format.i]);
		if (valid_arg(format) < 1)
			format.error = 1;
		else
			format.numbers[format.i] = format.atoi;
		free(format.itoa);
	}
	free_array(format.args, format.length);
	if (format.error)
	{
		free(format.numbers);
		return (format);
	}
	return (format);
}

static t_index	get_more_index(t_index index, int *numbers, int length)
{
	while (!index.j && !index.error && ++index.i < length)
	{
		if (index.max > numbers[index.i])
		{
			index.max = numbers[index.i];
			index.at = index.i;
		}
	}
	while (index.j && !index.error && ++index.i < length)
	{
		if (index.max > numbers[index.i] && numbers[index.i] > index.min)
		{
			index.max = numbers[index.i];
			index.at = index.i;
		}
		else if (index.max == numbers[index.i])
			index.error = 1;
	}
	return (index);
}

t_index	get_index_utils(t_index index, int *numbers, int length)
{
	index.j = -1;
	index.state = 1;
	index.at = -1;
	index.error = 0;
	while (!index.error && ++index.j < length)
	{
		index.i = -1;
		index.max = 4294967295;
		index = get_more_index(index, numbers, length);
		index.index[index.at] = index.state;
		index.registered[index.at] = index.max;
		index.state++;
		index.min = index.max;
	}
	return (index);
}
