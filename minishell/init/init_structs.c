/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:11:28 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/08 22:59:19 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// t_env	*init_env()
// {
// 	t_env	*env;

// 	env = ft_calloc(sizeof(t_env), 1);
// 	if (!env)
// 		return (NULL);
// 	env->key = init_string();
// 	env->value = init_string();
// 	env->info = NULL;
// 	env->next = NULL;
// 	env->prev = NULL;
// 	return (env);
// }

t_cmd	init_cmd()
{
	t_cmd	cmd;

	cmd.cmd = NULL;
	cmd.args = NULL;
	cmd.splitter = UNDEFINED_SPLITTER;
	cmd.next = NULL;
	cmd.result = NULL;
	return (cmd);
}

t_history	init_history()
{
	t_history	history;

	history.cmd_executed = NULL;
	history.cmd = NULL;
	history.next = NULL;
	history.prev = NULL;
	return (history);
}
