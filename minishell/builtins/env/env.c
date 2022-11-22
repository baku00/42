/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:34:39 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/22 23:33:00 by my_name_         ###   ########.fr       */
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