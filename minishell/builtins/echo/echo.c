/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:56:36 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/04 19:49:20 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

char	*exec_echo(t_minishell *minishell)
{
	(void) minishell;
    return (ft_strdup("echo"));
}