/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:43 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 02:03:40 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct s_remove
{
	char	**args;
	int		i;
}	t_remove;

static char	**remove_file_name(int argc, char **argv)
{
	t_remove	remove;

	remove.args = ft_calloc(sizeof(char *), argc + 1);
	remove.i = 0;
	while (argv[++remove.i])
	{
		free(remove.args[remove.i - 1]);
		remove.args[remove.i - 1] = ft_strdup(argv[remove.i]);
	}
	return (remove.args);
}

static int	next(t_arguments arguments, t_sort sort)
{
	sort.a = ft_int_array_dup(arguments.numbers, arguments.length);
	sort.a_counter = arguments.length;
	free(arguments.numbers);
	if (!sort.a)
		return (0);
	sort.b = ft_calloc(sizeof(int), arguments.length);
	sort.b_counter = 0;
	sort.max_length = arguments.length;
	if (!is_sorted(sort))
	{
		if (arguments.length <= 5)
			sort_small(sort);
		else
			sort_big(sort);
	}
	free(sort.a);
	free(sort.b);
	return (0);
}

int	main(int argc, char **argv)
{
	char		**args;
	int			i;
	t_arguments	arguments;
	t_sort		sort;

	argc -= 1;
	args = remove_file_name(argc, argv);
	arguments = check_argument(argc, args);
	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
	if (arguments.error)
	{
		if (arguments.show_error)
			ft_printf("Error\n");
		return (0);
	}
	return (next(arguments, sort));
}
