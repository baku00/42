#include "../../../../../so_long.h"

char	*checkCoin(t_mlx *mlx, int x, int y)
{
  char *point;
  char  *result;

  point = ft_calloc(1, sizeof(char));
  point = get_point(point, x, y);
  result = ft_strnstr(mlx->coin->point.point, point, ft_strlen(mlx->coin->point.point));
  if (ft_strnstr(mlx->coin->coin_taked.point, point, ft_strlen(mlx->coin->coin_taked.point)))
    return NULL;
  else
    mlx->coin->coin_taked.point = ft_strjoin(mlx->coin->coin_taked.point, point);
  free(point);
  return result;
}
