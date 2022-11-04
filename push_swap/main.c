/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:43 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 17:06:06 by dgloriod         ###   ########.fr       */
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
		ft_printf("Error\n");
		return (0);
	}
	sort.a = ft_int_array_dup(arguments.numbers, arguments.length);
	sort.a_counter = arguments.length;
	free(arguments.numbers);
	if (!sort.a)
		return (0);
	sort.b = ft_calloc(sizeof(int), arguments.length);
	sort.b_counter = arguments.length;
	sort.max_length = arguments.length;
	if (arguments.length <= 5)
		sort_small(sort);
	free(sort.a);
	free(sort.b);
	return (0);
}
