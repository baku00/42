#include "../../so_long.h"

void	ft_create_map(t_mlx *mlx)
{
	t_window	window;

	mlx->ptr = mlx_init();
	window.width = (mlx->file.width - 1) * ITEM_WIDTH;
	window.height = (mlx->file.height) * ITEM_HEIGHT;
	window.title = "So Long";
	window.ptr = \
	mlx_new_window(mlx->ptr, window.width, window.height, window.title);
	mlx->window = window;
}
