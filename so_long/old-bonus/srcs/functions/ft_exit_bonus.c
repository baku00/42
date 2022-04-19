/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:25 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:34:26 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_exit(char *message, int error)
{
	if (error)
		printf("\033[31;01mErreur: \033[00m");
	printf("%s\n", message);
	exit(0);
}
