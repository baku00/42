/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:32:44 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/08 23:01:23 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

// char	*create_line(char *prefix, char *split, char *suffix)
// {
// 	char	*result;

// 	result = ft_calloc(sizeof(char), 1);
// 	if (!result)
// 		return (NULL);
// 	result = ft_strjoin(result, prefix);
// 	if (!result)
// 		return (NULL);
// 	result = ft_strjoin(result, split);
// 	if (!result)
// 		return (NULL);
// 	result = ft_strjoin(result, suffix);
// 	if (!result)
// 		return (NULL);
// 	return (result);
// }

// char	*get_export(t_minishell *minishell)
// {
// 	char	*env;
// 	char	**split;
// 	char	*result;
// 	int		i;

// 	(void) minishell;
// 	env = exec_env(minishell);
// 	if (!env)
// 		return (NULL);
// 	split = ft_split(env, '\n');
// 	if (!split)
// 		return (NULL);
// 	result = ft_calloc(sizeof(char), 1);
// 	if (!result)
// 		return (NULL);
// 	i = -1;
// 	while (split[++i])
// 	{
		
// 		result = ft_strjoin(result, create_line(ft_strdup("declare -x "), split[i], ft_strdup("\n")));
// 		if (!result)
// 			return (NULL);
// 	}
// 	return (result);
// }

// char	*create_export(t_minishell *minishell, char *args)
// {
	
// }

char	*exec_export(t_minishell *minishell, char *args)
{
	(void) minishell;
	(void) args;
	return (NULL);
	// if (!args)
	// 	return (get_export(minishell));
	// else
	// 	return (create_export(minishell, args));
}