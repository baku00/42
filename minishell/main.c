/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:20 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 17:58:07 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
# define PIPE '|'
# define MORE_THAN '>'
# define LESS_THAN '<'
# define DOLLARS '$'

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	
	char	**splitted;

	splitted = ft_split(argv[1], ' ');
	int i = -1;
	while (splitted[++i])
	{
		printf("(%s)\n", splitted[i]);
		free(splitted[i]);
	}
	free(splitted);
	return (0);
}




// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/18 03:00:20 by my_name_          #+#    #+#             */
// /*   Updated: 2022/11/18 03:00:20 by my_name_         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <main.h>
// # include <stdlib.h>
// # include <readline/readline.h>
// # include <readline/history.h>

// // static char	*readline(const char *prompt)
// // {
// // 	char	str[200];
// // 	char	*s;

// // 	printf("%s", prompt);
// // 	scanf("%200[0-9a-zA-Z \"\'|<>]", str);
// // 	s = ft_strdup(str);
// // 	str[0] = '\0';
// // 	return (s);
// // }

// // static t_minishell	init_minishell()
// // {
// // 	t_minishell	minishell;

// // 	minishell.export = init_export();
// // 	minishell.env = init_env();
// // 	minishell.path = init_path();
// // 	minishell.history = init_history();
// // 	minishell.cmd = NULL;
// // 	minishell.have_to_exit = 0;
// // 	return (minishell);
// // }

// int	main(int argc, char **argv)
// {
// 	// t_minishell	minishell;
// 	// t_cmd		cmd;

// 	(void) argc;
// 	(void) argv;
// 	// (void) minishell;
// 	// (void) cmd;
// 	// minishell = init_minishell();
// 	// minishell.path = get_default_path();
// 	// cmd = init_cmd();
// 	// minishell.history.cmd = &cmd;
// 	// printf("")
// 	// printf("CHDIR: %d\n", chdir("/home/user/42"));
// 	// // create_path_from_directory("/home/user/42");
// 	// exec_cd(&minishell, "~");
// 	// // exec_pwd(&minishell);

// 	printf("Change directory: (%d)\n", exec_cd(NULL, argv[1]));
// 	printf("PWD: (%s)\n", exec_pwd());
// 	execve("/bin/ls", argv, argv);
// 	return (0);
// }
