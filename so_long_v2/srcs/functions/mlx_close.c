#include "../../so_long.h"

int	mlx_close(t_mlx *mlx)
{
	int	y;
	int	x;

	free(mlx->file.content);
	y = -1;
	while (++y < mlx->file.height)
		free(mlx->file.point[y]);
	free(mlx->file.point);
	exit(0);
	return (0);
}
