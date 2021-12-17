#include "../../../../so_long.h"

int	down(t_mlx *mlx)
{
	mlx->player.point.current_y = mlx->player.point.y + 1;
	mlx->player.point.current_x = mlx->player.point.x;
	return (move(mlx));
}
