/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:56:42 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/09 19:27:15 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *mlx, int x, int y, int i)
{
	int	h;
	int	w;

	h = x * 64;
	w = y * 64;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites[i].img, w, h);
}

int	put_wall_image(int i)
{
	if (i == 0)
		return (10);
	else
		return (1);
	return (1);
}

void	initialize_imgs_2(t_data *mlx, int width, int height)
{
	mlx->sprites[8].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/calci4.xpm",
			&width, &height);
	mlx->sprites[9].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/wall2.xpm",
			&width, &height);
	mlx->sprites[10].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/wall3.xpm",
			&width, &height);
}

void	initialize_imgs(t_data *mlx)
{
	int		width;
	int		height;

	width = 1080;
	height = 720;
	mlx->sprites[0].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/calci1.xpm",
			&width, &height);
	mlx->sprites[1].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/wall1.xpm",
			&width, &height);
	mlx->sprites[2].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/ground.xpm",
			&width, &height);
	mlx->sprites[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/fireplace.xpm", &width, &height);
	mlx->sprites[4].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/water.xpm", &width, &height);
	mlx->sprites[5].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/wood.xpm", &width, &height);
	mlx->sprites[6].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/calci2.xpm",
			&width, &height);
	mlx->sprites[7].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/calci3.xpm",
			&width, &height);
	initialize_imgs_2(mlx, width, height);
}
