#include "../../../../so_long.h"

void	print_move(t_mlx *mlx)
{
	char	*move;

	move = ft_itoa(mlx->player.move);
	put_wall(mlx, 0, 0);
	put_wall(mlx, 0, 1);
	put_wall(mlx, 0, 2);
	put_wall(mlx, 0, 3);
	put_wall(mlx, 0, 4);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 0, 10, 0xffffff, mlx->message.movement);
	mlx_string_put(mlx->ptr, mlx->window.ptr, 80, 10, 0xffffff, move);
	free(move);
}
