/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:47:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:25:34 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "so_long_bonus.h"
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <time.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
}			t_image;

typedef struct s_player
{
	int			x;
	int			y;
	int			collected;
	int			collectable;
	int			index;
	int			player_moved;
}			t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**matrix;
	int			matrix_i;
	int			matrix_j;
	t_image		sprites[12];
	t_player	player_cor;
	int			move_happened;
	int			move;
	int			lives;
}			t_data;

void	handle_lives(t_data *mlx, int i, int j);
void	check_counters(t_data *mlx, int *counters);
void	enemies_movment(t_data *mlx);
void	free_matrix(char **mat);
int		put_wall_image(int i);
void	display_map(t_data *mlx, int index);
int		map_len(char *map_file, int fd);
void	initialize_imgs(t_data *mlx);
void	player_movment(t_data *mlx, int horizontal, int vertical);
void	put_image(t_data *mlx, int x, int y, int i);
int		open_exit(int collected, int collectable);
void	populate_map(t_data *mlx, char *mapfile);
void	initialize_imgs_2(t_data *mlx, int width, int height);
void	display_enemies(t_data *mlx, int i, int j);
int		handle_enemies(t_data *mlx);
void	map_parsing(t_data *mlx);
char	*ft_strchr(const char *s, int c);
void	flood_fill(char **map, int i, int j, t_data *mlx);
void	find_player(t_data *mlx);
char	**ft_matrix_dup(char **matrix);
size_t	ft_strlen(const char *src);
int		exit_function(t_data *mlx);
void	display_moves(t_data *mlx, int n_moves);
int		number_len(int n);
int		n_enemies(t_data *mlx);

#endif