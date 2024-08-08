/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:54:04 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:25:53 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	show_text(t_data *mlx, char *string, char *prev_string)
{
	mlx_string_put(mlx->mlx, mlx->win, 45,
		(mlx->matrix_i + 0.4) * 64, 00000, prev_string);
	mlx_string_put(mlx->mlx, mlx->win, 45,
		(mlx->matrix_i + 0.4) * 64, 0xffffff, string);
}

void	display_moves(t_data *mlx, int n_moves)
{
	char	*final_string;
	char	*move_numbers;
	int		final_len;
	char	*prev_string;
	char	*string;

	move_numbers = ft_itoa(n_moves);
	final_len = ft_strlen(move_numbers) + 7;
	final_string = ft_strjoin("Moves: ", move_numbers);
	if (n_moves == 0)
		n_moves ++;
	string = ft_itoa(n_moves - 1);
	prev_string = ft_strjoin("Moves: ", string);
	show_text(mlx, final_string, prev_string);
	free(move_numbers);
	free(final_string);
	free(prev_string);
	free(string);
}
