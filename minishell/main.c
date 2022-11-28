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

typedef struct s_args
{
	char	*arg;
	char	*substr;
	void	*next;
	void	*prev;
	int		splitter;
	int		double_char;
	char	*result;
}	t_args;

int		find_next(char *arg, int i, char c);
int		find_next_dollars(char *arg, int i, char c, char c2);
char	*check_var(char	*str);
int		is_char(char c, char c1, char c2, char c3);
t_args	*parser(t_args *prev, char *arg, int i);

int	find_next(char *arg, int i, char c)
{
	while (arg[++i] && arg[i] != c)
		;
	if (!arg[i])
		i = -1;
	return (i);
}

int	find_next_dollars(char *arg, int i, char c, char c2)
{
	while (arg[++i] && arg[i] != c && arg[i] != c2)
		;
	if (!arg[i])
		i = 0;
	if (arg[i] == c2)
		i *= -1;
	return (i);
}

int	get_sub(int	next)
{
	if (next < 0)
		next *= -1;
	return (next);
}

char	*get_string_if_dollars(char *str, int is_dollar)
{
	char	*env;

	if (is_dollar)
		env = ft_strdup(getenv(str));
	else
		env = ft_strdup(str);
	free(str);
	return (env);
}

typedef struct s_check_var
{
	int		i;
	int		next;
	char	*formated;
	char	*substr;
}	t_check_var;

char	*check_var(char	*str)
{
	t_check_var	vc;

	vc.i = -1;
	vc.formated = ft_calloc(sizeof(char), 1);
	if (!vc.formated)
		return (NULL);
	while (str[++vc.i])
	{
		vc.next = 1;
		if (str[vc.i] == DOLLARS)
			vc.next = find_next_dollars(str, vc.i, SPACE, DOLLARS);
		vc.substr = ft_substr(str, vc.i + (str[vc.i] == DOLLARS), get_sub(vc.next));
		if (!vc.substr)
			return (NULL);
		vc.substr = get_string_if_dollars(vc.substr, str[vc.i] == DOLLARS);
		vc.formated = ft_strjoin(vc.formated, vc.substr);
		if (!vc.formated)
			return (NULL);
		if (str[vc.i] == DOLLARS)
			vc.i = vc.next;
	}
	free(str);
	return (vc.formated);
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
	char	next_c;

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
			next = find_next(arg, i, c);
			if (next == -1)
				return (NULL);
			args->substr = ft_substr(arg, i + 1, (next - 1) - i);
			if (!args->substr)
				return (NULL);
			if (c == GUILLEMET)
				args->substr = check_var(args->substr);
			args->arg = ft_strjoin(args->arg, args->substr);
			i = next;
			if (!args->arg)
				return (NULL);
		}
		else if (c == PIPE || c == MORE_THAN || c == LESS_THAN)
		{
			args->splitter = c;
			next_c = arg[i + 1];
			args->double_char = next_c == PIPE || next_c == MORE_THAN || next_c == LESS_THAN;
			if (is_char(arg[i + 2], PIPE, MORE_THAN, LESS_THAN))
				return (NULL);
			if (args->double_char)
				i += 1;
			args->next = parser(args, arg, i);
			break;
		}
		else
		{
			args->substr = ft_substr(arg, i, 1);
			args->arg = ft_strjoin(args->arg, args->substr);
			if (!args->arg)
				return (NULL);
		}
	}
	return (args);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	//t_args *args = parser("'1\"1'   \"Hello ''\"  '22'  | '\"Comment ça va ?\"'     '33'    ", -1);
	t_args *args = parser(NULL, argv[1], -1);
	printf("\n\n\n");
	if (!args)
		printf("Error\n");
	while(args)
	{
		printf("Pointer: (%p)\n", args);
		printf("Next: (%p)\n", args->next);
		printf("Prev: (%p)\n", args->prev);
		printf("Arg: (%s)\n", args->arg);
		free(args->arg);
		printf("Splitter: (%c%c)\n", args->splitter, args->double_char ? args->splitter : '\0');
		printf("Double char: (%d)\n", args->double_char);
		printf("Result: (%s)\n\n", args->result);
		if (args->prev)
			free(args->prev);
		if (!args->next)
		{
			free(args);
			args = NULL;
		}
		else
			args = args->next;
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
