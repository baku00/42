/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/30 18:46:40 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H

/*
	char *arg		les éléments en chaîne de caractères		"6 5 4"
	char **args		les éléments en tableau de caractères		["6", "5", "4"]
	int counter		le nombre total d'éléments					3
	int *numbers	les éléments en tableau d'entier			[6, 5, 4]
*/

typedef struct argument
{
	char	*arg;
	char	**args;
	int		counter;
	int		*numbers;
}	t_argument;
#endif
