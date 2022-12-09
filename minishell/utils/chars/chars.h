/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:17:53 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/01 16:16:05 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARS_H
# define CHARS_H
# include <main.h>

int	is_char(char c, char *cs);
int	find_next_chars(char *arg, int i, char c1, char c2);
int	find_next(char *arg, int i, char c);
#endif