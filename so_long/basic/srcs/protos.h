/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:36:17 by dgloriod          #+#    #+#             */
/*   Updated: 2022/05/28 01:55:30 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H
# include "../so_long.h"

typedef struct s_mlx
{
	void			*ptr;
	t_window		window;
	t_elements		elements;
	t_file			file;
}	t_mlx;
int			main(int argc, char **argv);
t_elements	init_elements(void);
t_file		init_file(void);
t_window	init_window(void);
t_mlx		init_mlx(void);
void		ft_exit(t_mlx *mlx, char *message, int error);
void		ft_check_file(t_mlx *mlx, char *filename);
bool		check_char(t_mlx *mlx, int y, int x);
bool		valid_char(t_mlx *mlx, int y, int x);
void		check_limit(t_mlx *mlx);
void		ft_create_map(t_mlx *mlx);
void		clean_file(t_mlx *mlx);
void		clean_image(t_mlx *mlx);
void		clean_mlx(t_mlx *mlx);
void		set_images(t_mlx *mlx);
// void		apply_move(t_mlx *mlx);
int			key_hook(int keycode, t_mlx *mlx);
int			mlx_close(t_mlx *mlx);
void		get_collectible(t_mlx *mlx, int y, int x);
int			move(t_mlx *mlx, int y, int x);
void		win(t_mlx *mlx);
void		print_ath(t_mlx *mlx);
void		lose(t_mlx *mlx);
void		init_wall_empty_collectible(t_elements *e);
t_exit		init_exit(void);
t_player	init_player(void);
// int			can_move(t_mlx *mlx, int y, int x);
#endif
