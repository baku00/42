/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:40:52 by my_name_          #+#    #+#             */
/*   Updated: 2022/12/04 20:33:06 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <main.h>
# include "./cd/cd.h"
# include "./pwd/pwd.h"
# include "./env/env.h"
# include "./echo/echo.h"
# include "./exit/exit.h"
# include "./export/export.h"
# include "./pwd/pwd.h"
# include "./unset/unset.h"
void	exec_cmd(t_minishell *minishell, t_args *args);
#endif