/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:17 by dgloriod          #+#    #+#             */
/*   Updated: 2022/02/05 18:36:18 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H
# include "../so_long_bonus.h"

typedef struct s_mlx
{
	void			*ptr;
	t_window		window;
	t_elements		elements;
	t_file			file;
}	t_mlx;
int		main(int argc, char **argv);
void	ft_exit(char *message, int error);
void	ft_check_file(t_mlx *mlx, char *filename);
void	check_char(t_mlx *mlx, int y, int x);
void	check_limit(t_mlx *mlx);
void	ft_create_map(t_mlx *mlx);
void	set_images(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		mlx_close(t_mlx *mlx);
void	get_collectible(t_mlx *mlx, int y, int x);
int		move(t_mlx *mlx, int y, int x);
void	win(t_mlx *mlx);
void	print_ath(t_mlx *mlx);
void	lose(t_mlx *mlx);
void	change_animations(t_mlx *mlx);
#endif
