/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:08:55 by dgloriod          #+#    #+#             */
/*   Updated: 2021/12/15 04:58:33 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_define
{
	char empty;
	char wall;
	char start_player_position;
	char coin;
	char exit;
} t_define;

typedef struct s_point
{
	int x;
	int y;
	int	**point;
}	t_point;

typedef struct s_player
{
	void *img;
	t_point	point;
	int	move;
}	t_player;

typedef struct s_coin
{
	void *img;
	t_point *point;
	int	count;
}	t_coin;

typedef struct s_wall
{
	void *img;
	t_point *point;
}	t_wall;

typedef struct s_empty
{
	void *img;
	t_point *point;
}	t_empty;

typedef struct s_exit
{
	void *img;
	t_point *point;
	int is_enable;
}	t_exit;

typedef struct s_item
{
	int height;
	int width;
	int x;
	int y;
}	t_item;

typedef struct s_window
{
	int		height;
	int		width;
	char	*title;
}	t_window;

typedef struct s_map
{
	int width;
	int height;
	char *filename;
	int fd;
	char **line;
}	t_map;

typedef struct s_mlx
{
	void *ptr;
	t_define	define;
	t_window	window;
	t_item		item;
	t_player	player;
	t_wall		wall;
	t_coin		coin;
	t_exit		exit;
	t_empty		empty;
	t_map		map;
}	t_mlx;

int		main(int argc, char **argv);
void	error(void);
void init_game(t_mlx *mlx, char *filename);
t_window	init_window(void);
t_define	init_define(void);
t_item	init_item(void);
t_wall	init_wall(void);
t_empty	init_empty(void);
t_exit	init_exit(void);
t_player	init_player(void);
t_coin	init_coin(void);
t_map	init_map(char *filename);

#endif
