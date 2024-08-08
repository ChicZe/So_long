/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:17:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/12 18:28:36 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	change_sprites(int horizontal, int vertical)
{
	if (horizontal == 1)
		return (0);
	else if (horizontal == -1)
		return (6);
	else if (vertical == -1)
		return (8);
	else if (vertical == 1)
		return (7);
	return (0);
}

int	count_collectable(t_data *mlx)
{
	int			i;
	int			j;
	int			coin;

	coin = 0;
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
			if (mlx->matrix[i][j] == 'C')
				coin++;
	}
	return (coin);
}

int	check_collide(t_data *mlx, int x, int y)
{
	static int	collected;
	static int	collectable;

	if (!collectable)
		collectable = count_collectable(mlx);
	if (mlx->matrix[x][y] == '1')
		return (0);
	else if (mlx->matrix[x][y] == 'E')
	{
		if (open_exit(collected, collectable) == 1)
			(void)(ft_printf("you won!\n") + exit_function(mlx));
		return (0);
	}
	else if (mlx->matrix[x][y] == 'C')
	{
		collected++;
		mlx->matrix[x][y] = 'P';
	}
	else if (mlx->matrix[x][y] == 'W')
		return (handle_enemies(mlx));
	mlx->matrix[mlx->player_cor.x][mlx->player_cor.y] = '0';
	mlx->player_cor.player_moved = 1;
	return (1);
}

void	find_player(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (mlx->matrix[++i])
	{
		while (mlx->matrix[i][++j] != 0)
		{
			if (mlx->matrix[i][j] == 'P')
			{
				mlx->player_cor.x = i;
				mlx->player_cor.y = j;
			}
		}
		j = -1;
	}
}

void	player_movment(t_data *mlx, int horizontal, int vertical)
{
	int			x;
	int			y;
	static int	move;

	find_player(mlx);
	x = mlx->player_cor.x;
	y = mlx->player_cor.y;
	mlx->player_cor.index = change_sprites(horizontal, vertical);
	if (horizontal == 1 && check_collide(mlx, x, y + 1) == 1)
		mlx->matrix[x][y + 1] = 'P';
	else if (horizontal == -1 && check_collide(mlx, x, y - 1) == 1)
		mlx->matrix[x][y - 1] = 'P';
	else if (vertical == -1 && check_collide(mlx, x + 1, y) == 1)
		mlx->matrix[x + 1][y] = 'P';
	else if (vertical == 1 && check_collide(mlx, x - 1, y) == 1)
		mlx->matrix[x - 1][y] = 'P';
	if (mlx->player_cor.player_moved == 1)
		move++;
	mlx->player_cor.player_moved = 0;
	mlx->move = move;
	display_moves(mlx, move);
	enemies_movment(mlx);
	display_map(mlx, mlx->player_cor.index);
}
