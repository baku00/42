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
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_keys
{
	int	escape;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keys;

typedef struct s_error_message
{
	char	*wrong_count_argument;
	char	*wrong_map_width;
	char	*wrong_map_size;
	char	*wrong_map_close;
	char	*line_error;
	int		line_number_error;
	char	*wrong_map_format;
	char	*wrong_char_map;
	char	*invalid_char;
	char	*missing_char;
}	t_error_message;

typedef struct s_message
{
	char	*win;
	char	*movement;
}	t_message;

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
	int	x;
	int	y;
	int	current_x;
	int	current_y;
	int	**point;
}	t_point;

typedef struct s_empty
{
	void	*img;
	t_point	point;
}	t_empty;

typedef struct s_player
{
	void	*img;
	t_point	point;
	int		move;
}	t_player;

typedef struct s_wall
{
	void	*img;
	t_point	point;
}	t_wall;

typedef struct s_coin
{
	void	*img;
	t_point	point;
	int		count;
}	t_coin;

typedef struct s_exit
{
	void	*img;
	t_point	point;
	int		is_enable;
}	t_exit;

typedef struct s_line
{
	size_t	length;
	char	**line;
}	t_line;

typedef struct s_contains
{
	int	empty;
	int	wall;
	int	exit;
	int	player;
	int	coin;
}	t_contains;

typedef struct s_map
{
	int			width;
	int			height;
	int			fd;
	char		accepted_chars[6];
	char		char_to_string[2];
	int			item_width;
	int			item_height;
	int			line_counter;
	int			wall;
	int			empty;
	int			player;
	int			coin;
	int			exit;
	t_line		line;
	t_contains	contains;
}	t_map;

typedef struct s_window
{
	int		height;
	int		width;
	char	*title;
	void	*ptr;
}	t_window;

typedef struct s_mlx
{
	void			*ptr;
	t_window		window;
	t_map			map;
	t_exit			exit;
	t_coin			coin;
	t_wall			wall;
	t_player		player;
	t_empty			empty;
	t_point			point;
	t_define		define;
	t_message		message;
	t_error_message	error_message;
	t_keys			keys;
}	t_mlx;

int				main(int argc, char **argv);
void			error(char *message);
int				is_n_only(const char *str, \
				const char *search, const int length);
int				is_at(const char *str, const char c, const int i);
void			init_game(t_mlx *mlx, char *filename);
void			init_map(t_mlx *mlx, char *filename);
t_line			get_line(t_mlx *mlx);
t_define		init_define(void);
t_message		init_message(void);
t_error_message	init_error_message(void);
void			error(char *message);
void			verify_map(t_mlx *mlx);
char			*valid_map_shape(t_mlx *mlx);
void			init_window(t_mlx *mlx);
t_point			init_point(void);
void			put_image(t_mlx *mlx);
void			put_wall(t_mlx *mlx, int y, int x);
void			put_empty(t_mlx *mlx, int y, int x);
void			put_exit(t_mlx *mlx, int y, int x);
void			put_player(t_mlx *mlx, int y, int x);
void			put_coin(t_mlx *mlx, int y, int x);
t_keys			init_keys(void);
int				hook(int keycode, t_mlx *mlx);
int				mlx_close(t_mlx *mlx);
int				up(t_mlx *mlx);
int				down(t_mlx *mlx);
int				right(t_mlx *mlx);
int				left(t_mlx *mlx);
int				check_coin(t_mlx *mlx, int **point, int x, int y);
int				check_door(t_mlx *mlx, int **point, int x, int y);
int				check_wall(t_mlx *mlx, int **point, int x, int y);
void			remove_coin(t_mlx *mlx, int x, int y);
t_coin			init_coin(t_mlx *mlx);
void			enable_door(t_mlx *mlx, int x, int y);
int				win(t_mlx *mlx);
int				move(t_mlx *mlx);
void			print_move(t_mlx *mlx);
t_contains		init_contains(void);
int				valid_contains(t_contains contains);
void			contains_object(char *line, t_mlx *mlx);
#endif
