/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:06:44 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 16:54:00 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_matrix_dup(char **matrix)
{
	int		i;
	int		size;
	char	**dup;

	size = 0;
	while (matrix[size])
		size++;
	dup = ft_calloc(sizeof(char *), size + 1);
	i = -1;
	while (matrix[++i])
		dup[i] = strdup(matrix[i]);
	return (dup);
}

void	flood_fill(char **tab, int i, int j, t_data *mlx)
{
	if (i < 0 || j < 0 || i >= mlx->matrix_i - 1
		|| j >= (int)ft_strlen(mlx->matrix[i]))
		return ;
	if (tab[i][j] == 'F' || tab[i][j] == '1' || tab[i][j] == 'W' )
		return ;
	if (tab[i][j] == 'E')
	{
		tab[i][j] = 'F';
		return ;
	}
	tab[i][j] = 'F';
	flood_fill(tab, i -1, j, mlx);
	flood_fill(tab, i +1, j, mlx);
	flood_fill(tab, i, j - 1, mlx);
	flood_fill(tab, i, j + 1, mlx);
}

int	open_exit(int collected, int collectable)
{
	if (collected == collectable && collectable != 0)
		return (1);
	return (0);
}

void	check_counters(t_data *mlx, int *counters)
{
	if (counters[0] == 0 || counters[0] > 1)
	{
		ft_printf("invalid elements\n");
		exit_function(mlx);
	}
	else if (counters[1] == 0 || counters[1] > 1)
	{
		ft_printf("invalid elements\n");
		exit_function(mlx);
	}
	else if (counters[2] == 0)
	{
		ft_printf("invalid elements\n");
		exit_function(mlx);
	}
	if (counters[3] > 7)
	{
		ft_printf("to many enemies (dio bubu)\n");
		exit_function(mlx);
	}
}

int	n_enemies(t_data *mlx)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
			if (mlx->matrix[i][j] == 'W')
				count++;
	}
	return (count);
}
