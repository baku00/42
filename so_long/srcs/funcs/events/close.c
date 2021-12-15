#include "../../../so_long.h"

int	mlx_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
  exit(0);
}
