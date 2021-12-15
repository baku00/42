#include "../../../../../so_long.h"

int	checkDoor(t_mlx *mlx)
{
  return (mlx->player->point.x == mlx->exit->point.x && mlx->player->point.y == mlx->exit->point.y);
}
