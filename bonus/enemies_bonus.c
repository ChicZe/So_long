/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:12:29 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:18:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	replace_enemies(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
			if (mlx->matrix[i][j] == 'R')
				mlx->matrix[i][j] = 'W';
	}
}

int	check_move(t_data *mlx, int i, int j)
{
	if (mlx->matrix[i][j] == 'P'
		|| mlx->matrix[i][j] == '1'
		|| mlx->matrix[i][j] == 'E'
		|| mlx->matrix[i][j] == 'C'
		|| mlx->matrix[i][j] == 'W'
		|| mlx->matrix[i][j] == 'R')
	{
		mlx->move_happened = 0;
		return (0);
	}
	mlx->move_happened = 1;
	return (1);
}

void	random_move(t_data *mlx, int i, int j)
{
	int	random;

	srand(time(NULL));
	random = (rand() % 4);
	if (random == 1 && check_move(mlx, i, j + 1) == 1)
		mlx->matrix[i][j + 1] = 'R';
	else if (random == 0 && check_move(mlx, i, j - 1) == 1)
		mlx->matrix[i][j - 1] = 'R';
	else if (random == 2 && check_move(mlx, i + 1, j) == 1)
		mlx->matrix[i + 1][j] = 'R';
	else if (random == 3 && check_move(mlx, i - 1, j) == 1)
		mlx->matrix[i - 1][j] = 'R';
}

void	enemies_movment(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
		{
			if (mlx->matrix[i][j] == 'W')
			{
				random_move(mlx, i, j);
				if (mlx->move_happened == 1)
					mlx->matrix[i][j] = '0';
				else if (mlx->move_happened == 0)
					mlx->matrix[i][j] = 'R';
			}
		}
	}
	replace_enemies(mlx);
}

void	display_enemies(t_data *mlx, int i, int j)
{
	if (mlx->matrix[i][j] == 'W')
		put_image(mlx, i, j, 4);
}
