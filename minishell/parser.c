/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:20 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/04 22:57:38 by my_name_         ###   ########.fr       */
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

int	find_next_2(char *arg, int i, char c, char c2)
{
	while (arg[++i] && arg[i] != c && arg[i] != c2)
		;
	if (!arg[i])
		i -= 1;
	if (arg[i] == c2)
		i *= -1;
	return (i);
}

char	*check_var(char	*str)
{
	int		i;
	int		next;
	char	*formated;
	char	*substr;
	int		sub;
	char	*env;


	i = -1;
	formated = ft_calloc(sizeof(char), 1);
	if (!formated)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == DOLLARS)
		{
			next = find_next_2(str, i + 1, SPACE, DOLLARS);
			sub = next;
			if (sub < 0)
				sub *= -1;
			substr = ft_substr(str, i + 1, sub);
			if (!substr)
				return (NULL);
			env = getenv(substr);
			free(substr);
			formated = ft_strjoin(formated, ft_strdup(env));
			if (!formated)
				return (NULL);
			i = next;
		}
		else
		{
			substr = ft_substr(str, i, 1);
			if (!formated)
				return (NULL);
			formated = ft_strjoin(formated, substr);
			if (!formated)
				return (NULL);
		}
	}
	return (formated);
}

int	is_char(char c, char c1, char c2, char c3)
{
	return (c == c1 || c == c2 || c == c3);
}

t_args	*parser(t_args *prev, char *arg, int i)
{
	t_args	*args;
	int		next;
	char	c;

	args = ft_calloc(sizeof(t_args), 1);
	if (!args)
		return (NULL);
	args->splitter = 0;
	args->next = NULL;
	args->double_char = 0;
	args->result = NULL;
	args->prev = prev;
	args->arg = ft_calloc(sizeof(char), 1);
	if (!args->arg)
		return (NULL);
	while (arg[++i])
	{
		c = arg[i];
		if (c == APOSTROPHE || c == GUILLEMET)
		{
			args->splitter = c;
			next = find_next(arg, i, c);
			if (next == -1)
				return (NULL);
			args->substr = ft_substr(arg, i + 1, (next - 1) - i);
			if (!args->substr)
				return (NULL);
			if (c != APOSTROPHE)
				args->substr = check_var(args->substr);
			args->arg = ft_strjoin(args->arg, args->substr);
			i = next;
			if (!args->arg)
				return (NULL);
		}
		else if (c == PIPE || c == MORE_THAN || c == LESS_THAN)
		{
			args->splitter = c;
			args->double_char = is_char(arg[i + 1], PIPE, MORE_THAN, LESS_THAN);
			if (is_char(arg[i + 2], PIPE, MORE_THAN, LESS_THAN))
				return (NULL);
			if (args->double_char)
				i += 1;
			args->next = parser(args, arg, i);
			break;
		}
		else
		{
			args->arg = ft_strjoin(args->arg, ft_substr(arg, i, 1));
			if (!args->arg)
				return (NULL);
		}
	}
	if (args->splitter != PIPE && args->splitter != MORE_THAN && args->splitter != LESS_THAN)
		args->splitter = 0;
	return (args);
}

void	get_cmd(t_args	**args)
{
	int	next;
	char	*arg;

	while ((*args))
	{
		next = find_next((*args)->arg, 0, SPACE);
		if (next == -1)
			(*args)->cmd = ft_strdup((*args)->arg);
		else
			(*args)->cmd = ft_substr((*args)->arg, 0, next);
		if (!(*args)->cmd)
			return ;
		if (next > 0)
		{
			arg = ft_strdup((*args)->arg);
			free((*args)->arg);
			(*args)->arg = ft_substr(arg, next + 1, ft_strlen(arg));
		}
		else
		{
			(*args)->cmd = ft_strdup((*args)->arg);
			free((*args)->arg);
			(*args)->arg = NULL;
		}
		if ((*args)->next)
			(*args) = (*args)->next;
		else
			break;
	}
	while ((*args)->prev)
		(*args) = (*args)->prev;
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;

// 	//t_args *args = parser("'1\"1'   \"Hello ''\"  '22'  | '\"Comment ça va ?\"'     '33'    ", -1);
// 	t_args *args = parser(NULL, argv[1], -1);
// 	printf("\n\n\n");
// 	if (!args)
// 		printf("Error\n");
// 	while(args)
// 	{
// 		printf("Pointer: (%p)\n", args);
// 		printf("Next: (%p)\n", args->next);
// 		printf("Prev: (%p)\n", args->prev);
// 		printf("Arg: (%s)\n", args->arg);
// 		printf("Splitter: (%c%c)\n", args->splitter, args->double_char ? args->splitter : '\0');
// 		printf("Double char: (%d)\n", args->double_char);
// 		printf("Result: (%s)\n\n", args->result);
// 		args = args->next;
// 	}
// 	return (0);
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
