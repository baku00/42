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
#define PIPE '|'
#define MORE_THAN '>'
#define LESS_THAN '<'
#define DOLLARS '$'
#define NEW_LINE '\n'

int	find_next(char *arg, int i, char c)
{
	while (arg[++i] && arg[i] != c)
		;
	if (!arg[i])
		i = -1;
	return (i);
}

t_string	get_string(char *key, int start, int next)
{
	t_string	string;

	string = init_string();
	if (next > 0)
		string.value = ft_substr(key, start, next);
	else
		string.value = ft_strdup(key);
	if (!string.value)
		string.error = 1;
	if (!string.error)
		string.length = ft_strlen(string.value);
	return (string);
}

t_env	*create_env(t_env *prev, t_info_env *info, char **envp, int i)
{
	t_env	*env;
	int		next;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->prev = prev;
	env->info = info;
	next = find_next(envp[i], 0, '=');
	env->key = get_string(envp[i], 0, next);
	if (env->key.error)
		return (NULL);
	if (next > 0)
	{
		env->value = get_string(envp[i], next + 1, ft_strlen(envp[i]) - next);
		if (env->value.error)
			return (NULL);
	}
	else
		env->value = init_string();
	if (envp[i + 1])
		env->next = create_env(env, info, envp, i + 1);
	else
		env->next = NULL;
	return (env);
}

char	*find_key(t_env *env, char *key)
{
	t_env	*finder;
	int		length;
	int		strncmp;

	finder = env;
	length = ft_strlen(key);
	while (finder)
	{
		strncmp = ft_strncmp(finder->key.value, key, finder->key.length);
		if (length == finder->key.length && !strncmp)
			return (finder->value.value);
		finder = finder->next;
	}
	return (NULL);
}

char	*_readline(char *display)
{
	char	*line;
	char	*buffer;

	printf("%s", display);
	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	buffer[0] = getchar();
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (buffer[0] != NEW_LINE)
	{
		buffer[0] = getchar();
		if (buffer[0] == NEW_LINE)
			break;
		line = ft_strjoin(line, ft_strdup(buffer));
		if (!line)
			return (NULL);
	}
	free(buffer);
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	t_env		*env;
	t_info_env	info_env;

	(void) argc;
	(void) argv;
	(void) envp;

	char *line = _readline(": ");
	while (ft_strncmp(line, "exit", ft_strlen(line)))
	{
		printf("Line: (%s)\n", line);
		line = _readline(": ");
	}
	env = create_env(NULL, &info_env, envp, 0);
	printf("%s: (%s)\n", argv[1], find_key(env, argv[1]));
	return (0);
}

// while (env)
// {
// 	printf("Key: (%s)\n", env->key);
// 	printf("Value: (%s)\n", env->value);
// 	printf("Next: (%p)\n", env->next);
// 	printf("Prev: (%p)\n", env->prev);
// 	printf("\n");
// 	env = env->next;
// }
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
