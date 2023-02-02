#include "../includes/so_long.h"

//função para dar free na mlx
void	free_mlx(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
	{
		free(mlx->map[i++]);
	}
	free(mlx->map);
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->tile);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->item);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
