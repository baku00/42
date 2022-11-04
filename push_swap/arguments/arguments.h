/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/04 16:12:36 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H
# include "../main.h"

typedef struct s_arguments
{
	int	length;
	int	*numbers;
	int	error;
}	t_arguments;

t_arguments	check_argument(int argc, char **argv);

#endif