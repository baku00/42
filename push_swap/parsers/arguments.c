/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/30 17:59:49 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*array_to_string(char **argv)
{
	char	*string;
	int		i;

	string = ft_calloc(sizeof(char), 1);
	i = 0;
	while (argv[i])
	{
		string = ft_strjoin(string, argv[i]);
		i++;
	}
	return (string);
}

static int	char_counter(char const *str, int c)
{
	int	i;
	int	counter;
	int	is_set;

	i = 0;
	counter = 0;
	is_set = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_set = 1;
		if (str[i] != c && is_set == 1)
		{
			is_set = 0;
			counter++;
		}
		i++;
	}
	return (counter);
}

t_argument	parse_arguments(int argc, char **argv)
{
	t_argument	argument;

	if (argc)
		argument.arg = argv[1];
	else
		argument.arg = array_to_string(argv);
	argument.args = ft_split(argument.arg, ' ');
	argument.counter = char_counter(argument.arg, ' ') + 1;
	return (argument);
}
