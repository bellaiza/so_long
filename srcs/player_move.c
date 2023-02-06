#include "../includes/so_long.h"

// start hooks functions to wait player input
// when player input something the hook call key_input function below
int	player_move(t_game *game, t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_input, mlx);
	return(0);
}

// ask correct functions based on player input
int	key_input(int key, t_mlx *mlx)
{
	if (key == 'a')
		a_input(mlx);
	else if (key == 'd')
		d_input(mlx);
	else if (key == 'w')
		w_input(mlx);
	else if (key == 's')
		s_input(mlx);
	else if (key == 65307)
	{
		free_mlx(mlx);
		exit(1);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	map_base_print(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
							mlx->player, mlx->p_x, mlx->p_y);
	printf("Number of steps: %d\n", mlx->p_steps);
	return (0);
}
