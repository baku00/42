#include "../../../so_long.h"

void	init_game(t_mlx *mlx, char *filename)
{
	mlx->ptr = mlx_init();
	mlx->define = init_define();
	mlx->map = init_map(filename);
	mlx->window = init_window();
	mlx->item = init_item();
	mlx->wall = init_wall();
	mlx->coin = init_coin();
	mlx->player = init_player();
	mlx->exit = init_exit();
	mlx->empty = init_empty();
}
