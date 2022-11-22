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
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// static char	*readline(const char *prompt)
// {
// 	char	str[200];
// 	char	*s;

// 	printf("%s", prompt);
// 	scanf("%200[0-9a-zA-Z \"\'|<>]", str);
// 	s = ft_strdup(str);
// 	str[0] = '\0';
// 	return (s);
// }

static t_minishell	init_minishell()
{
	t_minishell	minishell;

	minishell.export = init_export();
	minishell.env = init_env();
	minishell.path = init_path();
	minishell.history = init_history();
	minishell.cmd = NULL;
	minishell.have_to_exit = 0;
	return (minishell);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_minishell	minishell;
	t_cmd		cmd;

	minishell = init_minishell();
	cmd = init_cmd();
	minishell.history.cmd = &cmd;
	exec_cd(&minishell, "./");
	exec_pwd(&minishell);
	return (0);
}
