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

t_builtin	*create_builtin(char *str, void *function, int return_type)
{
	t_builtin	*builtin;

	builtin = ft_calloc(sizeof(t_builtin), 1);
	if (!builtin)
		return (NULL);
	builtin->string = create_string(str);
	if (((t_string *) builtin->string)->error)
		return (NULL);
	builtin->function = function;
	builtin->return_type = return_type;
	return (builtin);
}

t_builtins	create_builtins()
{
	t_builtins	builtins;

	builtins.echo = create_builtin("echo", &exec_echo, STRING);
	builtins.cd = create_builtin("cd", &exec_cd, INT);
	builtins.pwd = create_builtin("pwd", &exec_pwd, STRING);
	builtins.export = create_builtin("export", &exec_export, STRING);
	builtins.unset = create_builtin("unset", &exec_unset, STRING);
	builtins.env = create_builtin("env", &exec_env, STRING);
	builtins.exit = create_builtin("exit", &exec_exit, INT);
	return (builtins);
}

static int	init_minishell(t_minishell **minishell)
{
	*minishell = ft_calloc(sizeof(t_minishell), 1);
	if (!minishell)
		return (0);
	// minishell->history = init_history();
	(*minishell)->read = NULL;
	(*minishell)->have_to_exit = 0;
	(*minishell)->builtins = create_builtins();
	return (1);
}

// static void handler(int signum)
// {
// 	(void) signum;
// }

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*minishell;

	(void) argc;
	(void) argv;
	(void) envp;
	init_minishell(&minishell);
	t_info_env	info_env;
	t_args		*args;
	(void) args;
	minishell->env = create_env(NULL, &info_env, envp, 0);
	// printf("%s: (%s)\n", argv[1], find_key(env, argv[1]));
	minishell->read = _readline(": ");
	printf("%s\n", minishell->read);
	while (ft_strncmp(minishell->read, "exit", ft_strlen(minishell->read)))
	{
		// printf("Before parser\n");
		minishell->args = parser(NULL, minishell->read, -1);
		get_cmd(&minishell->args);
		// printf("After parser\n");
		exec_cmd(minishell, minishell->args);
		// args = minishell->args;
		// while(args)
		// {
		// 	printf("Pointer: (%p)\n", args);
		// 	printf("Next: (%p)\n", args->next);
		// 	printf("Prev: (%p)\n", args->prev);
		// 	printf("CMD: (%s)\n", args->cmd);
		// 	printf("Arg: (%s)\n", args->arg);
		// 	printf("Splitter: (%c%c)\n", args->splitter, args->double_char ? args->splitter : '\0');
		// 	printf("Double char: (%d)\n", args->double_char);
		// 	printf("Result: (%s)\n\n", args->result);
		// 	args = args->next;
		// }
		free(minishell->read);
		minishell->read = _readline(": ");
		printf("%s\n", minishell->read);
	}
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
