/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:25 by dgloriod          #+#    #+#             */
/*   Updated: 2022/04/12 02:49:17 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_exit(t_mlx *mlx, char *message, int error)
{
	if (error)
		printf("\033[31;01mErreur: \033[00m");
	printf("%s\n", message);
	mlx_close(mlx);
}
