#include "../includes/so_long.h"

// constantly show game image on window
int	ft_expose(t_mlx *mlx)
{
	map_base_print(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
							mlx->player, mlx->p_x, mlx->p_y);
	return(0);
}

// function to close the game
int	close_game(t_mlx *mlx)
{
	free_mlx(mlx);
	exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	mlx.p_steps = 0;
	mlx.mlx = mlx_init();
	map_input(argc, argv, &game);
	map_size(&game);
	mlx.win = mlx_new_window(mlx.mlx, game.width, game.height, "LITTLE WITCH");
	mlx_expose_hook(mlx.win, ft_expose, &mlx);
	image_create(&game, &mlx);
	map_base_print(&mlx);
	initial_print(&game, &mlx);
	player_location(&mlx);
	player_move(&game, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
