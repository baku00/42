#ifndef WINDOW_H
# define WINDOW_H
# include "../header.h"

typedef struct s_window
{
	int		height;
	int		width;
	char	*title;
	void	*ptr;
}	t_window;
#endif
