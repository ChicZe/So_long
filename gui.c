/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:54:04 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/12 17:09:48 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_text(char *string)
{
	ft_printf("%s\n", string);
}

void	display_moves(int n_moves)
{
	char	*final_string;
	char	*move_numbers;
	int		final_len;

	move_numbers = ft_itoa(n_moves);
	final_len = ft_strlen(move_numbers) + 7;
	final_string = ft_strjoin("Moves: ", move_numbers);
	show_text(final_string);
	free(move_numbers);
	free(final_string);
}
