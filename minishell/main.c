/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:20 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:00:20 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static t_minishell	init_minishell()
{
	t_minishell	minishell;

	minishell.export = init_export();
	minishell.env = init_env();
	minishell.path = init_path();
	minishell.history = init_history();
	minishell.history.cmd = init_cmd();
	minishell.cmd = NULL;
	minishell.have_to_exit = 0;
	return (minishell);
}

int	main(int argc, char **argv)
{
	(void) argc;
	t_minishell	minishell;

	minishell = init_minishell();
	minishell.cmd = ft_strdup(getcmd(argv[1]));
	printf("(%s)\n", minishell.cmd);
	// while (!minishell.have_to_exit)
	// {
	// }
	return (0);
}
