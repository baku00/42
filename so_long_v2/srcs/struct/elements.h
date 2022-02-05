#ifndef ELEMENTS_H
# define ELEMENTS_H
# include "../header.h"

typedef struct s_wall
{
	void		*img;
	int			count;
}	t_wall;

typedef struct s_exit
{
	void		*img;
	int			is_enabled;
	int			x;
	int			y;
	int			count;
}	t_exit;

typedef struct s_collectible
{
	void		*img;
	int			count;
	int			total_count;
}	t_collectible;

typedef struct s_empty
{
	void		*img;
}	t_empty;

typedef struct s_player
{
	void		*img;
	int			x;
	int			y;
	int			current_x;
	int			current_y;
	int			count;
	int			movement;
}	t_player;

typedef struct s_elements
{
	t_collectible	collectible;
	t_exit			exit;
	t_player		player;
	t_wall			wall;
	t_empty			empty;
}	t_elements;
#endif
