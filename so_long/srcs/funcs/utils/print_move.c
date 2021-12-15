#include "../../../so_long.h"

void print_move(t_mlx *mlx)
{
  char  *move;

  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall->img, 0, 0);
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall->img, 40, 0);
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall->img, 80, 0);
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->wall->img, 120, 0);
  move = ft_itoa(mlx->player->move);
  mlx_string_put(mlx->mlx, mlx->window, 0, 10, 0xffffff, "Deplacement: ");
  mlx_string_put(mlx->mlx, mlx->window, 90, 10, 0xffffff, move);
  free(move);
}
