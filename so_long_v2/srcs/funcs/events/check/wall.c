#include "../../../../so_long.h"

int	check_wall(t_mlx *mlx, int **point, int x, int y)
{
	return (point[y][x] == mlx->define.wall);
}
