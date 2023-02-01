#include "../includes/so_long.h"

void	map_base_print(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < mlx->row)
	{
		col = 0;
		while (col < mlx->col)
		{	
			if (mlx->map[row][col] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, \
										(col * 32), (row * 32));
			else if (mlx->map[row][col] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, \
										(col * 32), (row * 32));
			else if (mlx->map[row][col] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item, \
										(col * 32), (row * 32));
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tile, \
										(col * 32), (row * 32));
			col++;
		}
		row++;
	}
}

int	player_location(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < mlx->row)
	{
		col = 0;
		while (col < mlx->col)
		{	
			if (mlx->map[row][col] == 'P')
			{
				mlx->p_x = col * 32;
				mlx->p_y = row * 32;
			}
			col++;
		}
		row++;
	}
	return(0);
}

int	initial_print(t_game *game, t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{	
			if (game->map[row][col] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, \
										(col * 32), (row * 32));
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item, \
										(col * 32), (row * 32));
			if (game->map[row][col] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, \
										(col * 32), (row * 32));
			col++;
		}
		row++;
	}
	return(0);
}

int	map_size(t_game *game)
{
	game->width = game->col * 32;
	game->height = game->row * 32;
	return (0);
}

void	image_create(t_game *game, t_mlx *mlx)
{
	mlx->new_c_flag = 0;
	mlx->old_c_flag = game->c_flag;
	mlx->map = game->map;
	mlx->col = game->col;
	mlx->row = game->row;
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, \
									"images/wall.xpm", &mlx->x, &mlx->y);
	mlx->tile = mlx_xpm_file_to_image(mlx->mlx, \
									"images/tile.xpm", &mlx->x, &mlx->y);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, \
									"images/player.xpm", &mlx->x, &mlx->y);
	mlx->item = mlx_xpm_file_to_image(mlx->mlx, \
									"images/item.xpm", &mlx->x, &mlx->y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, \
									"images/exit.xpm", &mlx->x, &mlx->y);
}
