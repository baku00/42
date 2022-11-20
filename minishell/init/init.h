/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:01:48 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/20 22:11:37 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <main.h>
t_export	init_export();
t_env		init_env();
t_path		init_path();
t_cmd		init_cmd();
t_history	init_history();
t_result	init_result();
#endif