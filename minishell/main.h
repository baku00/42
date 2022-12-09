/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:10 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 03:00:10 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "headers/headers.h"

int	main(int argc, char **argv, char **envp);
t_args	*parser(t_args *prev, char *arg, int i);
int	find_next(char *arg, int i, char c);
void	get_cmd(t_args	**args);
#endif
