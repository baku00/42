#include "../../../so_long.h"

int	hook(int keycode, t_mlx *mlx)
{
  if (keycode == ESCAPE)
    mlx_close(mlx);
  else if (keycode == UP)
  {
    mlx->player->move += 1;
    print_move(mlx);
    up(mlx);
  }
  else if (keycode == DOWN)
  {
    mlx->player->move += 1;
    print_move(mlx);
    down(mlx);
  }
  else if (keycode == LEFT)
  {
    mlx->player->move += 1;
    print_move(mlx);
    left(mlx);
  }
  else if (keycode == RIGHT)
  {
    mlx->player->move += 1;
    print_move(mlx);
    right(mlx);
  }
  return 0;
}
