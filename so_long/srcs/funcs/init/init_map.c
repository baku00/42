#include "../../../so_long.h"

t_map	init_map(char *filename)
{
	t_map map;

	map.width = 0;
	map.height = 0;
	map.filename = filename;
	// map.line = ft_calloc(1, sizeof(char *));
	map.fd = open(filename, O_RDONLY);
	return (map);
}
