/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:42:40 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/05 01:58:37 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_builtin(char *cmd, int length, t_builtin *builtin)
{
	int			strncmp;
	t_string	*string;

	string = builtin->string;
	strncmp = ft_strncmp(cmd, string->value, length);
	return (length == string->length && !strncmp);
}

static void	*is_builtins(char *cmd, t_builtins builtins)
{
	int	length;

	length = ft_strlen(cmd);
	if (is_builtin(cmd, length, builtins.echo))
		return (builtins.echo);
	if (is_builtin(cmd, length, builtins.cd))
		return (builtins.cd);
	if (is_builtin(cmd, length, builtins.pwd))
		return (builtins.pwd);
	if (is_builtin(cmd, length, builtins.export))
		return (builtins.export);
	if (is_builtin(cmd, length, builtins.unset))
		return (builtins.unset);
	if (is_builtin(cmd, length, builtins.env))
		return (builtins.env);
	if (is_builtin(cmd, length, builtins.exit))
		return (builtins.exit);
	return (NULL);
}

void	exec_cmd(t_minishell *minishell, t_args *args)
{
	t_builtin *builtin;
	char	*(*function)(void *);
	char **a = ft_calloc(sizeof(char *), 1);

	builtin = is_builtins(args->cmd, minishell->builtins);
	if (builtin)
	{
		function = builtin->function;
		printf("Pointer: %p => %p\n", builtin->function, &exec_echo);
		printf("=> (%s)\n", ((function)(minishell)));
	}
	else
	{
		fork();
		execve(args->cmd, a, a);
	}
}
