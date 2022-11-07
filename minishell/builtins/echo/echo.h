/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:54:46 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 02:57:12 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H
# include <main.h>

typedef struct s_echo
{
	int		has_option;
	char	**string;
}	t_echo;

void	echo(char	**args);

#endif