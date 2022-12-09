/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:12:25 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/04 20:20:25 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	*create_string(char *str)
{
	t_string	*string;

	string = ft_calloc(sizeof(t_string), 1);
	configure_string(&string);
	string->value = ft_strdup(str);
	if (!string->value)
	{
		string->error = 1;
		return (string);
	}
	string->length = ft_strlen(string->value);
	return (string);
}
