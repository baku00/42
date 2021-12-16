#include "../../../so_long.h"

void	init_game(t_mlx *mlx, char *filename)
{
	mlx->ptr = mlx_init();
	mlx->test = 2;
	// mlx->map = init_map(filename);
}
