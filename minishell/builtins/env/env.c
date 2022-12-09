/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/08 22:59:54 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_home()
{
	char	*path;
	int		home_length;

	path = getenv("HOME");
	home_length = ft_strlen(path);
	if (path[0] == '/')
		path = ft_substr(path, 1, home_length - 1);
	return (getenv("HOME"));
}

// t_string	get_string(char *key, int start, int next)
// {
// 	t_string	string;

// 	string = init_string();
// 	if (next > 0)
// 		string.value = ft_substr(key, start, next);
// 	else
// 		string.value = ft_strdup(key);
// 	if (!string.value)
// 		string.error = 1;
// 	if (!string.error)
// 		string.length = ft_strlen(string.value);
// 	return (string);
// }

// void	create_env_entry(t_minishell *minishell, char *key, char *value)
// {
// 	t_env		*env;
// 	t_string	*string;
// 	int			strncmp;

// 	env = minishell->env;
// 	while (env)
// 	{
// 		string = env->key;
// 		strncmp = ft_strncmp(string->value, key, string->length);
// 		if (strncmp > 0)
// 		else if (strncmp < 0)
// 		else
// 			env = save_env()
// 		if (env->next)
// 			env = env->next;
// 		else
// 			break;
// 	}
// }

// t_env	*create_env(t_env *prev, t_info_env *info, char **envp, int i)
// {
// 	t_env	*env;
// 	int		next;

// 	env = ft_calloc(sizeof(t_env), 1);
// 	if (!env)
// 		return (NULL);
// 	env->prev = prev;
// 	env->info = info;
// 	info->last = env;
// 	next = find_next(envp[i], 0, '=');
// 	env->key = get_string(envp[i], 0, next);
// 	if (env->key.error)
// 		return (NULL);
// 	if (next > 0)
// 	{
// 		env->value = get_string(envp[i], next + 1, ft_strlen(envp[i]) - next);
// 		if (env->value.error)
// 			return (NULL);
// 	}
// 	else
// 		env->value = init_string();
// 	if (envp[i + 1])
// 		env->next = create_env(env, info, envp, i + 1);
// 	else
// 		env->next = NULL;
// 	return (env);
// }

// char	**get_strings(char *envp)
// {
// 	char	**result;
// 	char	*substr;
// 	int		next;
// 	int		sub;
// 	int		length;

// 	length = ft_strlen(envp);
// 	result = ft_calloc(sizeof(char *), 3);
// 	if (!result)
// 		return (NULL);
// 	next = find_next(envp, 0, '=');
// 	if (next == -1)
// 		sub = ft_strlen(envp);
// 	else
// 		sub = next;
// 	result[0] = ft_substr(envp, 0, sub);
// 	if (!result[0])
// 		return (NULL);
// 	if (next)
// 	{
// 		result[1] = ft_substr(envp, sub, length - sub);
// 		if (!result[1])
// 			return (NULL);
// 	}
// 	else
// 	{
// 		free(result[1]);
// 		result[1] = NULL;
// 	}
// 	return (result);
// }

// // Enregistre une entrée dans la liste
// void	register_env()

// // Créer une nouvelle entrée
// t_env	*create_env(char *key, char *value)
// {
// 	t_env	*env;


// 	env = ft_calloc(sizeof(t_env), 1);
// 	if (!env)
// 		return (NULL);
// 	env->key = create_string(key);
// 	if (value)
// 		env->value = create_string(value);
// 	else
// 		env->value = NULL;
// }

// // Génère la liste
// t_env	*generate_env(t_prev *prev, char **envp, int i)
// {
// 	t_env	*env;

// 	env = create_env(envp[i]);
// 	env->prev = prev;
// 	if (envp[i + 1])
// 		env->next = generate_env(env, envp, i + 1);
// 	return (env);
// }

// char	*find_key(t_env *env, char *key)
// {
// 	t_env	*finder;
// 	int		length;
// 	int		strncmp;

// 	finder = env;
// 	length = ft_strlen(key);
// 	while (finder)
// 	{
// 		strncmp = ft_strncmp(finder->key.value, key, finder->key.length);
// 		if (length == finder->key.length && !strncmp)
// 			return (finder->value.value);
// 		finder = finder->next;
// 	}
// 	return (NULL);
// }

// char	*exec_env(t_minishell *minishell)
// {
// 	t_env		*env;
// 	t_string	string;
// 	char		*result;

// 	env = minishell->env;
// 	result = ft_calloc(sizeof(char), 1);
// 	if (!result)
// 		return (NULL);
// 	while (env)
// 	{
// 		string = env->key;
// 		result = ft_strjoin(result, ft_strdup(string.value));
// 		if (!result)
// 			return (NULL);
// 		result = ft_strjoin(result, ft_strdup("="));
// 		if (!result)
// 			return (NULL);
// 		string = env->value;
// 		if (string.value)
// 		{
// 			result = ft_strjoin(result, ft_strdup(string.value));
// 			if (!result)
// 				return (NULL);
// 		}
// 		result = ft_strjoin(result, ft_strdup("\n"));
// 			if (!result)
// 				return (NULL);
// 		env = env->next;
// 	}
// 	return (result);
// }