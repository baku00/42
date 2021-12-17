#include "../../../../so_long.h"

int	right(t_mlx *mlx)
{
	mlx->player.point.current_y = mlx->player.point.y;
	mlx->player.point.current_x = mlx->player.point.x + 1;
	return (move(mlx));
}
