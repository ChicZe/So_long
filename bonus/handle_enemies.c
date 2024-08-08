/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:19:01 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:19:10 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_enemies(t_data *mlx)
{
	printf("you touched water!\n");
	mlx->lives--;
	if (mlx->lives == 0)
		exit_function(mlx);
	return (0);
}
