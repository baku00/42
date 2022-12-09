/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:54:31 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/09 04:39:40 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

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

t_env	*generate_env(t_env *prev, char **envp, int i)
{
	t_env	*env;

	env = create_env_with_next(envp[i], find_next(envp[i], 0, '='));
	if (!env)
		return (NULL);
	env->prev = prev;
	if (envp[i + 1])
		env->next = generate_env(env, envp, i + 1);
	return (env);
}

t_env	*find_position(t_env *list, t_env *current)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void) argc;
	(void) argv;
	(void) envp;
	(void) env;
	// int i = -1;
	// while (envp[++i])
	// 	printf("[%d]: %s\n", i, envp[i]);
	// printf("\n\n\n\n\n");
	env = generate_env(NULL, envp, 0);
	while (env)
	{
		printf("%s=%s\n", ((t_string *)env->key)->value, ((t_string *) env->value)->value);
		env = env->next;
	}
	return (0);
}
