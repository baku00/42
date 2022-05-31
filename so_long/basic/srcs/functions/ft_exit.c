/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:34:25 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/31 19:24:29 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_exit(t_mlx *mlx, char *message, int error)
{
	if (error)
		ft_putstr_fd("\033[31;01mErreur: \033[00m", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	mlx_close(mlx);
}
