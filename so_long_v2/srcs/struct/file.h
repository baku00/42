#ifndef FILE_H
# define FILE_H
# include "../header.h"
typedef struct s_file
{
	char	*name;
	char	*content;
	char	*line;
	int		width;
	int		height;
	int		**point;
	int		fd;
	size_t	content_length;
}	t_file;
#endif
