#include "../../so_long.h"

void	print_ath(t_mlx *mlx)
{
	printf("----------------------\n");
	printf("Nombre de movements:\t%d\n", mlx->elements.player.movement);
	printf("Pièce récupéré:\t\t%d\n", mlx->elements.collectible.total_count - mlx->elements.collectible.count);
	printf("Pièce restante:\t\t%d\n", mlx->elements.collectible.count);
}
