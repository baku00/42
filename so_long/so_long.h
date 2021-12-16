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
# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include "mlx/mlx.h"
# include "keys.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# ifndef CONST
#  define CONST
#  define SRCS "./srcs"
#  define IMG SRCS"/img"
#  define MAPS SRCS"/maps"
#  define EMPTY 'O'
#  define EMPTY '0'
#  define WALL '1'
#  define COLLECTIBLE 'C'
#  define EXIT 'E'
#  define START_PLAYER_POSITION 'P'
# endif
typedef struct s_define
{
	char	empty;
	char	wall;
	char	collectible;
	char	exit;
	char	start_player_position;
}	t_define;

typedef struct s_point
{
	int		x;
	int		y;
	char	*point;
}	t_point;

typedef struct s_empty
{
	t_point	point;
	void	*img;
}	t_empty;

typedef struct s_player
{
	t_point	point;
	void	*img;
	int		move;
}	t_player;

typedef struct s_wall
{
	t_point	point;
	void	*img;
}	t_wall;

typedef struct s_coin
{
	int		count;
	t_point	point;
	t_point	coin_taked;
	void	*img;
}	t_coin;

typedef struct s_exit
{
	t_point	point;
	void	*img;
	int		is_enable;
}	t_exit;

typedef struct s_map
{
	int		width;
	int		height;
	int		fd;
	char	*line;
	char	*previous_line;
	char	accepted_chars[6];
	char	char_to_string[2];
	int		item_margin_width;
	int		item_margin_height;
	int		item_width;
	int		item_height;
	int		length;
	int		first;
	char	*test;
}	t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	int			height;
	int			width;
	t_coin		*coin;
	t_exit		*exit;
	t_player	*player;
	t_wall		*wall;
	t_empty		*empty;
	t_map		*map;
	t_define	define;
}	t_mlx;

int		main(int argc, char **argv);
int		valid_map(char *filename, t_map *map);
void	error(char *message);
int		valid_shape(char *filename, t_map *map);
int		is_n_only(const char *str, const char *search, const int length);
int		is_at(const char *str, const char c, const int i);
int		hook(int keycode, t_mlx *mlx);
int		mlx_close(t_mlx *mlx);
int		left(t_mlx *mlx);
int		right(t_mlx *mlx);
int		down(t_mlx *mlx);
int		up(t_mlx *mlx);
char	*get_point(char *point, int x, int y);
char	*check_wall(t_mlx *mlx, int x, int y);
char	*check_coin(t_mlx *mlx, int x, int y);
int		check_door(t_mlx *mlx);
void	win(void);
void	remove_coin(t_mlx *mlx);
void	print_move(t_mlx *mlx);

#endif
