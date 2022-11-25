/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:47:35 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/23 22:27:44 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../builtins.h"

int		dir_exist(char *path);
void	create_path(t_minishell *minishell, char *path);
t_path	get_default_path();

#endif