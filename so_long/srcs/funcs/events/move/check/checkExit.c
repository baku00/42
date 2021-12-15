#include "../../../../../so_long.h"

char	*checkWall(t_mlx *mlx, int x, int y)
{
  char *point;
  char  *result;

  point = ft_calloc(1, sizeof(char));
  point = get_point(point, x, y);
  result = ft_strnstr(mlx->wall->point.point, point, ft_strlen(mlx->wall->point.point));
  free(point);
  return result;
}
