#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	char	*line;
	char	*map_file;
	int		gnl;
	int		fd;
	int		fd_row;
	int		row;
	int		col;
	int		map_flag;
	int		c_flag;
	int		p_flag;
	int		e_flag;
	int		width;
	int		height;
}	t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*tile;
	void	*player;
	void	*item;
	void	*exit;
	char	**map;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		width;
	int		height;
	int		row;
	int		col;
	int		new_c_flag;
	int		old_c_flag;
	int		p_steps;
}	t_mlx;

void	image_create(t_game *game, t_mlx *mlx);
void	map_base_print(t_mlx *mlx);
void	a_input(t_mlx *mlx);
void	d_input(t_mlx *mlx);
void	w_input(t_mlx *mlx);
void	s_input(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
void	a_input_exit(t_mlx *mlx);
void	d_input_exit(t_mlx *mlx);
void	w_input_exit(t_mlx *mlx);
void	s_input_exit(t_mlx *mlx);
int		error_reading(void);
int		map_input(int argc, char **argv, t_game *game);
int		check_ber(t_game *game, char *ber);
int		map_deal(t_game *game);
int		map_row(t_game *game);
int		map_check_wall(t_game *game);
int		map_check_inside(t_game *game);
int		check_inside_error(t_game *game);
int		map_print(t_game *game, t_mlx *mlx);
int		map_size(t_game *game);
int		map_check_zero(t_game *game);
int		initial_print(t_game *game, t_mlx *mlx);
int		player_move(t_game *game, t_mlx *mlx);
int		key_input(int key, t_mlx *mlx);
int		player_location(t_mlx *mlx);
int		close_game(t_mlx *mlx);
int		init_screen(void);
int		ft_expose(t_mlx *mlx);

#endif