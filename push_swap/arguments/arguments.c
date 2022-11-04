/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:42 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 16:12:46 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

static int	valid_number(int argc)
{
	return (argc >= 1);
}

typedef struct s_format
{
	char	**args;
	char	*itoa;
	int		atoi;
	int		length;
	int		strlen;
	int		*numbers;
	int		i;
	int		error;
}	t_format;

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
	format.i = -1;
	format.error = 0;
	while (!format.error && ++format.i < format.length)
	{
		format.atoi = ft_atoi(format.args[format.i]);
		format.itoa = ft_itoa(format.atoi);
		format.strlen = ft_strlen(format.args[format.i]);
		if (ft_strncmp(format.args[format.i], format.itoa, format.strlen))
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

t_arguments	check_argument(int argc, char **argv)
{
	t_arguments	arguments;
	t_format	format;

	arguments.error = 0;
	if (!valid_number(argc))
		arguments.error = 1;
	if (!arguments.error)
		format = check_format(argc, argv);
	if (format.error)
		arguments.error = 1;
	if (arguments.error)
		return (arguments);
	arguments.numbers = ft_int_array_dup(format.numbers, format.length);
	arguments.length = format.length;
	free(format.numbers);
	return (arguments);
}
