/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:58 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:25:45 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	number_len(int n)
{
	int	count;

	count = 0;
	if (!n || n == 0)
		return (0);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	free_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	mat = NULL;
}

int	exit_function(t_data *mlx)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	while (++j < 12)
		mlx_destroy_image(mlx->mlx, mlx->sprites[j].img);
	while (mlx->matrix[++i])
		free(mlx->matrix[i]);
	free(mlx->matrix);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	map_len(char *map_file, int fd)
{
	char	*line;
	int		len;

	len = 0;
	fd = open(map_file, O_RDONLY);
	line = "first";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (line[0] != 10)
			len++;
		free(line);
	}
	close(fd);
	return (len);
}

void	handle_lives(t_data *mlx, int i, int j)
{
	if (mlx->lives == 2)
	{
		put_image(mlx, i - 1, j - 2, 11);
		put_image(mlx, i - 1, j - 3, 11);
	}
	else
		put_image(mlx, i - 1, j - 3, 11);
}
