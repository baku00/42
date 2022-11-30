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

int	find_next(char *arg, int i, char c)
{
	while (arg[++i] && arg[i] != c)
		;
	if (!arg[i])
		i = -1;
	return (i);
}

t_env	*create_env(t_env *prev, char **envp, int i)
{
	t_env	*env;
	int		next;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->prev = prev;
	next = find_next(envp[i], 0, '=');
	if (next > 0)
		env->key = ft_substr(envp[i], 0, next);
	else
		env->key = ft_strdup(envp[i]);
	if (!env->key)
		return (NULL);
	if (next > 0)
	{
		env->value = ft_substr(envp[i], next + 1, ft_strlen(envp[i]) - next);
		if (!env->value)
			return (NULL);
	}
	else
		env->value = NULL;
	if (envp[i + 1])
		env->next = create_env(env, envp, i + 1);
	else
		env->next = NULL;
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	
	t_env	*env;

	env = create_env(NULL, envp, 0);
	while (env)
	{
		printf("Key: (%s)\n", env->key);
		printf("Value: (%s)\n", env->value);
		printf("Next: (%p)\n", env->next);
		printf("Prev: (%p)\n", env->prev);
		printf("\n");
		env = env->next;
	}
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
