/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:12:33 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/17 02:14:59 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_table	create_table(void)
{
	t_table	table;

	table.have_to_stop = 0;
	table.has_finish = 0;
	table.start_time = 0;
	table.time_to_die = 0;
	return (table);
}
