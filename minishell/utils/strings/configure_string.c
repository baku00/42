/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:56:43 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/04 20:21:11 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	configure_string(t_string **string)
{
	t_string	model;

	model = init_string();
	(*string)->value = model.value;
	(*string)->length = model.length;
	(*string)->error = model.error;
}
