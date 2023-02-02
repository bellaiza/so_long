#include "../includes/so_long.h"

// check if quantity of game essential objects are valid 
int	check_inside_error(t_game *game)
{
	if (game->e_flag == 0 || game->c_flag == 0 || game->p_flag != 1)
	{
		printf("\nERROR: Please insert at least 1 player/item/exit!\n");
		exit(1);
		return (1);
	}
	map_check_zero(game);
	return (0);
}

// check if symbols used in the map are all valid
int	map_check_zero(t_game *game)
{
	int	row;
	int	col;

	game->map_flag = 0;
	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{	
			if (game->map[row][col] == '0' || game->map[row][col] == '1' || \
			game->map[row][col] == 'P' || game->map[row][col] == 'C' || \
			game->map[row][col] == 'E')
				game->map_flag++;
			else
			{
				printf ("The map must contain only 0,1,P,C or E :) \n");
				exit(1);
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

// check if map file extension is .ber
int	check_ber(t_game *game, char *ber)
{
	int	counter;
	int	length;

	length = ft_strlen(ber);
	counter = 0;
	while (game->map_file[counter + 1])
		counter++;
	while (counter >= 0 && game->map_file[counter] != '.')
		counter--;
	if (counter >= 0 && !ft_strncmp(game->map_file + counter + 1, ber, length))
		return (1);
	return (0);
}

// an auxilar function to print an error and exit immediatly
int	error_reading(void)
{
	printf("\nIt seems like there's a error in the map reading :/\n");
	exit(1);
	return (1);
}
