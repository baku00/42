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
	void	*next;
	void	*prev;
	int		splitter;
	int		double_char;
	char	*result;
}	t_args;

int	find_next(char *arg, int i, char c)
{
	while (arg[++i] && arg[i] != c)
		;
	if (!arg[i])
		i = -1;
	return (i);
}

t_args	*parser(char *arg, int i)
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
			args->arg = ft_strjoin(args->arg, ft_substr(arg, i + 1, (next - 1) - i));
			i = next;
			if (!args->arg)
				return (NULL);
		}
		else
		{
			args->arg = ft_strjoin(args->arg, ft_substr(arg, i, 1));
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
	t_args *args = parser("'1\"1'   \"Hello ''\"  '22'   '\"Comment ça va ?\"'     '33''    ", -1);
	printf("\n\n\n");
	if (!args)
		printf("Error\n");
	while(args)
	{
		printf("Arg: (%s)\n", args->arg);
		printf("Splitter: (%c)\n\n", args->splitter);
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
