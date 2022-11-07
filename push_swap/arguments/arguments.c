/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:42 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 01:08:15 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

static int	valid_number(int argc)
{
	return (argc >= 1);
}

static t_format	check_format(int argc, char **argv)
{
	t_format	format;

	if (argc == 1)
		format.args = ft_split(argv[0], ' ');
	else
		format.args = ft_array_dup(argv);
	if (!format.args)
	{
		format.error = 1;
		return (format);
	}
	format.length = ft_array_length(format.args);
	format.numbers = ft_calloc(sizeof(int), format.length);
	if (!format.numbers)
	{
		free_array(format.args, format.length);
		format.error = 1;
		return (format);
	}
	format = check_format_utils(format);
	return (format);
}

static int	*get_index(int *numbers, int length)
{
	t_index	index;

	index.index = ft_calloc(sizeof(int), length);
	if (!index.index)
		return (NULL);
	index.registered = ft_calloc(sizeof(int), length);
	if (!index.registered)
		return (NULL);
	index = get_index_utils(index, numbers, length);
	free(index.registered);
	if (index.error)
	{
		free(index.index);
		return (NULL);
	}
	return (index.index);
}

t_arguments	check_argument(int argc, char **argv)
{
	t_arguments	arguments;
	t_format	format;

	arguments.error = 0;
	arguments.show_error = 1;
	if (!valid_number(argc))
	{
		arguments.error = 1;
		arguments.show_error = 0;
	}
	if (!arguments.error)
		format = check_format(argc, argv);
	if (format.error)
		arguments.error = 1;
	if (arguments.error)
		return (arguments);
	arguments.numbers = get_index(format.numbers, format.length);
	arguments.length = format.length;
	if (!arguments.numbers)
		arguments.error = 1;
	free(format.numbers);
	return (arguments);
}
