#include "../../../../so_long.h"

void	enable_door(t_mlx *mlx, int x, int y)
{
	mlx->exit.is_enable = 1;
	mlx->point.point[y][x] = mlx->define.exit;
	mlx_put_image_to_window(mlx->ptr, mlx->window.ptr, mlx->exit.img, x * mlx->map.item_width, y * mlx->map.item_height);
}
