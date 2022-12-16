/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:13:00 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/13 01:08:03 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H
# include <main.h>
t_string	*create_string(char *str);
t_string	init_string();
void		configure_string(t_string **string);
char		*get_string(t_string *str);
int			get_string_length(t_string *str);
int			get_string_error(t_string *str);
void		free_string(t_string *string);
t_string	*string_copy(t_string *str);
#endif