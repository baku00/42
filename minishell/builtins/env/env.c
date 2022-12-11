/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/11 04:11:15 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_env(t_env *env)
{
	while (env)
	{
		printf("This: %p\n", env);
		printf("Key: (%s)\n", ((t_string *)env->key)->value);
		printf("Value: (%s)\n", ((t_string *)env->value)->value);
		printf("Info: %p\n", env->info);
		printf("Info first: %p\n", ((t_info *) env->info)->first);
		printf("Info last: %p\n", ((t_info *) env->info)->last);
		printf("Next: %p\n", env->next);
		printf("Prev: %p\n", env->prev);
		printf("\n\n\n");
		env = env->next;
	}
}

static t_env	*init_env()
{
	t_env	*env;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
	env->prev = NULL;
	env->n = 0;
	return (env);
}

t_env	*create_env(char *key, char *value)
{
	t_env	*env;

	env = init_env();
	if (!env)
		return (NULL);
	if (!key)
		return (NULL);
	env->key = create_string(key);
	if (((t_string *) env->key)->error)
		return (NULL);
	if (value)
	{
		env->value = create_string(value);
		if (((t_string *) env->value)->error)
			return (NULL);
		free(value);
	}
	free(key);
	return (env);
}

static t_env	*create_env_with_next(char *envp, int next)
{
	int		length;
	int		sub;
	char	*key;
	char	*value;

	length = ft_strlen(envp);
	sub = next;
	if (next == -1)
		sub = length;
	key = ft_substr(envp, 0, sub);
	if (!key)
		return (NULL);
	value = NULL;
	if (next >= 0)
	{
		value = ft_substr(envp, next + 1, length - next);
		if (!value)
			return (NULL);
	}
	return (create_env(key, value));
}

t_env	*generate_env(t_env *prev, char **envp, t_info *info_env, int i)
{
	t_env	*env;

	env = create_env_with_next(envp[i], find_next(envp[i], 0, '='));
	if (!env)
		return (NULL);
	env->prev = prev;
	env->n += 1;
	env->info = info_env;
	info_env->length += 1;
	if (!prev)
		info_env->first = env;
	if (envp[i + 1])
		env->next = generate_env(env, envp, info_env, i + 1);
	else
		info_env->last = env;
	return (env);
}