/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/15 17:13:20 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_permissions(char *str)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return ;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(0);
	bytes_read = read(fd, buffer, 1);
	if (bytes_read < 0)
	{
		ft_printf("no file permissions");
		free(buffer);
		exit(0);
	}
	free(buffer);
}

char	*file_validation(char *str)
{
	char	*map_path;
	int		end;

	end = ft_strlen(str) - 1;
	map_path = ft_strrchr(str, '.');
	if (ft_strncmp(map_path, ".ber", 4) != 0 || !map_path)
	{
		ft_printf("invalid extension!\n");
		exit(0);
	}
	while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
	{
		str[end] = 0;
		end --;
	}
	check_permissions(str);
	return (str);
}

int	on_keydown(int key, t_data *img)
{
	img->player_cor.index = 4;
	if (key == 65307)
		exit_function(img);
	else if (key == 119)
		player_movment(img, 0, 1);
	else if (key == 115)
		player_movment(img, 0, -1);
	else if (key == 97)
		player_movment(img, -1, 0);
	else if (key == 100)
		player_movment(img, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
	{
		ft_printf("invalid map argument\n");
		return (0);
	}
	ft_bzero(&img, sizeof(img));
	argv[1] = file_validation(argv[1]);
	img.mlx = mlx_init();
	populate_map(&img, argv[1]);
	if (!img.move)
		display_moves(0);
	mlx_key_hook(img.win, on_keydown, &img);
	mlx_loop(img.mlx);
}
