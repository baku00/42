/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:22:37 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 00:28:47 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*get_string(t_string *str)
{
	if (!str)
		return (NULL);
	return (str->value);
}

int	get_string_length(t_string *str)
{
	if (!str)
		return (0);
	return (str->length);
}

int	get_string_error(t_string *str)
{
	if (!str)
		return (0);
	return (str->error);
}