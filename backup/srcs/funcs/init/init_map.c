#include "../../../so_long.h"

t_map	init_map(char *filename)
{
	t_map map;

	map.width = 10;
	map.height = 0;
	map.filename = filename;
	map.fd = open(filename, O_RDONLY);
	return (map);
}
