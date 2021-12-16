#include "../../../so_long.h"

void	init_game(t_mlx *mlx, char *filename)
{
	mlx->ptr = mlx_init();
	mlx->map = init_map(filename);
}
