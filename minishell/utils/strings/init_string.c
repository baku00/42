/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:12:25 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/03 17:15:29 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	init_string()
{
	t_string	string;

	string.value = NULL;
	string.length = 0;
	string.error = 0;
	return (string);
}
