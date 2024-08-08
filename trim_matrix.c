/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:34:29 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/11 19:08:13 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**trim_matrix(t_data *mlx)
{
	int	i;

	i = -1;
	while (mlx->matrix[++i])
	{
		if (mlx->matrix[i][0] == '\n')
			mlx->matrix[i] = 0;
	}
	return (mlx->matrix);
}
