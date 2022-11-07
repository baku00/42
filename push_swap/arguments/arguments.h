/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:38:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 01:09:02 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H
# include "../main.h"

typedef struct s_index
{
	long	max;
	int		min;
	int		at;
	int		i;
	int		j;
	int		*index;
	int		*registered;
	int		started;
	int		error;
	int		state;
}	t_index;

typedef struct s_arguments
{
	int	length;
	int	*numbers;
	int	error;
	int	show_error;
}	t_arguments;

typedef struct s_format
{
	char	**args;
	char	*itoa;
	int		atoi;
	int		length;
	int		strlen;
	int		*numbers;
	int		i;
	int		error;
}	t_format;

t_arguments	check_argument(int argc, char **argv);
t_format	check_format_utils(t_format format);
t_index		get_index_utils(t_index index, int *numbers, int length);

#endif