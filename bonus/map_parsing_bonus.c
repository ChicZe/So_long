/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:23:05 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:01:38 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_coins(char **temp)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
			if (temp[i][j] == 'C')
				return (1);
	}
	return (0);
}

void	check_path(t_data *mlx)
{
	char	**temp;
	int		i;
	int		j;

	i = -1;
	temp = ft_matrix_dup(mlx->matrix);
	find_player(mlx);
	flood_fill(temp, mlx->player_cor.x, mlx->player_cor.y, mlx);
	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == 'E' || check_coins(temp) == 1)
			{
				ft_printf("no valid path!\n");
				free_matrix(temp);
				exit_function(mlx);
			}
		}
	}
	free_matrix(temp);
}

void	check_walls(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
		{
			if ((i == 0 || i == mlx->matrix_i - 1) && mlx->matrix[i][j] != '1')
			{
				ft_printf("invalid walls\n");
				exit_function(mlx);
			}
			else if (mlx->matrix[i][0] != '1'
					|| mlx->matrix[i][strlen(mlx->matrix[i]) - 1] != '1')
			{
				ft_printf("invalid walls\n");
				exit_function(mlx);
			}
		}
	}
}

void	check_elements(t_data *mlx)
{
	int		counters[4];
	int		i;
	int		j;

	counters[0] = 0;
	counters[1] = 0;
	counters[2] = 0;
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
		{
			if (mlx->matrix[i][j] == 'P')
				counters[0]++;
			else if (mlx->matrix[i][j] == 'E')
				counters[1]++;
			else if (mlx->matrix[i][j] == 'C')
				counters[2]++;
			else if (!ft_strchr("10PCEW", mlx->matrix[i][j]))
				(void)(ft_printf("invalid elements\n") + exit_function(mlx));
		}
	}
	counters[3] = n_enemies(mlx);
	check_counters(mlx, counters);
}

void	map_parsing(t_data *mlx)
{
	int	i;
	int	j;
	int	line;
	int	count;

	line = 0;
	count = 0;
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[0][++j])
			line++;
		j = -1;
		while (mlx->matrix[i][++j])
			count++;
		if (line != count)
		{
			printf("the map is not regualar\n");
			exit_function(mlx);
		}
	}
	check_elements(mlx);
	check_walls(mlx);
	check_path(mlx);
}
