#include "../includes/so_long.h"

int	map_input(int argc, char **argv, t_game *game)
{
	if (argc == 1)
	{
		printf ("\nERROR: Please input a valid maps/<file_name>.ber\n");
		exit(1);
		return (1);
	}
	if (argc == 2)
	{
		game->map_file = argv[1];
		if (!check_ber(game, "ber"))
		{
			printf("ERROR: Please input a valid .ber type of file\n");
			exit (1);
			return (1);
		}
		printf ("\nYour desired map is %s\n\n", game->map_file);
	}
	map_deal(game);
	return (0);
}

int	map_deal(t_game *game)
{
	int		gnl;
	int		index;
	char	*temp;

	map_row(game);
	game->fd = open (game->map_file, O_RDONLY);
	if (game->fd == -1)
		error_reading();
	index = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(game->fd, &temp);
		game->map[index] = ft_strdup(temp);
		free(temp);
		index++;
	}
	game->map[game->row] = NULL;
	game->col = ft_strlen (game->map[0]);
	close (game->fd);
	map_check_wall(game);
	map_check_inside(game);
	return (0);
}

int	map_row(t_game *game)
{
	int		ret;
	char	c;

	game->fd_row = open (game->map_file, O_RDONLY);
	if (!(game->fd_row))
		error_reading();
	game->row = 1;
	ret = 1;
	while (ret)
	{
		ret = read(game->fd_row, &c, 1);
		if (ret < 0)
			return (1);
		if (c == '\n')
			game->row++;
	}
	game->map = (char **) ft_calloc(game->row + 1, sizeof(char *));
	if (game->map == NULL)
		error_reading();
	close(game->fd_row);
	return (0);
}

int	map_check_wall(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (row == 0 || row == (game->row - 1) || \
			col == 0 || col == (game->col - 1))
			{
				if (game->map[row][col] != '1')
				{
					printf("\nERROR: The map surroundings must be walls only!\n");
					exit(1);
					return (1);
				}
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	map_check_inside(t_game *game)
{
	int	row;
	int	col;

	game->p_flag = 0;
	game->c_flag = 0;
	game->e_flag = 0;
	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{	
			if (game->map[row][col] == 'C')
				game->c_flag++;
			if (game->map[row][col] == 'P')
				game->p_flag++;
			if (game->map[row][col] == 'E')
				game->e_flag++;
			col++;
		}
		row++;
	}
	check_inside_error(game);
	return (0);
}
