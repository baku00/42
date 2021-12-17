#include "../../../../so_long.h"

int	check_door(t_mlx *mlx, int **point, int x, int y)
{
	return (point[y][x] == mlx->define.exit);
}
