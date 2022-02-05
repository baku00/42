#include "../../so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		mlx_close(mlx);
	else if (keycode == UP)
		mlx->elements.player.movement += move(mlx, -1, 0);
	else if (keycode == DOWN)
		mlx->elements.player.movement += move(mlx, 1, 0);
	else if (keycode == LEFT)
		mlx->elements.player.movement += move(mlx, 0, -1);
	else if (keycode == RIGHT)
		mlx->elements.player.movement += move(mlx, 0, 1);
	print_ath(mlx);
	return (0);
}
