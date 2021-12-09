#include "../../so_long.h"

void  print_wall(t_mlx *mlx, int x, int y)
{
  mlx_pixel_put(mlx->ptr, mlx->window, x, y, color);
}
