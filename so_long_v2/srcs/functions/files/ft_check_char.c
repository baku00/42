#include "../../../so_long.h"

void check_char(t_mlx *mlx, int y, int x)
{
	if (mlx->file.point[y][x] == 'C')
	{
		mlx->elements.collectible.count++;
		mlx->elements.collectible.total_count++;
	}
	else if (mlx->file.point[y][x] == 'E')
	{
		mlx->elements.exit.x = x;
		mlx->elements.exit.y = y;
		mlx->elements.exit.count++;
	}
	else if (mlx->file.point[y][x] == '1')
		mlx->elements.wall.count++;
	else if (mlx->file.point[y][x] == 'P')
	{
		mlx->elements.player.x = x;
		mlx->elements.player.y = y;
		mlx->elements.player.count++;
	}
}

void check_limit(t_mlx *mlx)
{
	if (mlx->elements.wall.count > MAX_WALL_LIMIT && \
		MAX_WALL_LIMIT != -1)
		ft_exit(ERROR_TO_MANY_WALL, 1);
	else if (mlx->elements.wall.count < MIN_WALL_LIMIT)
		ft_exit(ERROR_NOT_ENOUGH_WALL, 1);
	else if (mlx->elements.player.count > MAX_PLAYER_LIMIT && \
		MAX_PLAYER_LIMIT != -1)
		ft_exit(ERROR_TO_MANY_PLAYER, 1);
	else if (mlx->elements.player.count < MIN_PLAYER_LIMIT)
		ft_exit(ERROR_NOT_ENOUGH_PLAYER, 1);
	else if (mlx->elements.collectible.count > MAX_COLLECTIBLE_LIMIT && \
		MAX_COLLECTIBLE_LIMIT != -1)
		ft_exit(ERROR_TO_MANY_COLLECTIBLE, 1);
	else if (mlx->elements.collectible.count < MIN_COLLECTIBLE_LIMIT)
		ft_exit(ERROR_NOT_ENOUGH_COLLECTIBLE, 1);
	else if (mlx->elements.exit.count > MAX_EXIT_LIMIT && \
		MAX_EXIT_LIMIT != -1)
		ft_exit(ERROR_TO_MANY_EXIT, 1);
	else if (mlx->elements.exit.count < MIN_EXIT_LIMIT)
		ft_exit(ERROR_NOT_ENOUGH_EXIT, 1);
}
