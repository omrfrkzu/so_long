/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:53:06 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/11 18:03:52 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	import_images1(t_data *data)
{
	int	img_width;
	int	img_height;

	data->sea = mlx_xpm_file_to_image(data->mlx,
			"textures/sea.xpm", &img_width, &img_height);
	if (!data->sea)
		error_exit(data);
	data->tile = mlx_xpm_file_to_image(data->mlx,
			"textures/greensea.xpm", &img_width, &img_height);
	if (!data->tile)
		error_exit(data);
	data->character_right = mlx_xpm_file_to_image(data->mlx,
			"textures/character.xpm", &img_width, &img_height);
	if (!data->character_right)
		error_exit(data);
	data->character_left = mlx_xpm_file_to_image(data->mlx,
			"textures/characterrev.xpm", &img_width, &img_height);
	if (!data->character_left)
		error_exit(data);
	data->berry = mlx_xpm_file_to_image(data->mlx,
			"textures/berry.xpm", &img_width, &img_height);
	if (!data->berry)
		error_exit(data);
}

void	import_images2(t_data *data)
{
	int	img_width;
	int	img_height;

	data->exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &img_width, &img_height);
	if (!data->exit)
		error_exit(data);
}

void	init_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(data);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = line;
		i++;
	}
	close(fd);
}

void	init_data(t_data *data)
{
	data->square_size = 100;
	if (data->window_width == 0 || data->window_height == 0)
		err(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(data);
	data->window = mlx_new_window(data->mlx, data->window_width * 100,
			data->window_height * 100, "so_long");
	if (!data->window)
		error_exit(data);
	import_images1(data);
	import_images2(data);
	data->character = data->character_right;
}

void	init_null(t_data *data)
{
	data->game_loop_counter = 0;
	data->move_counter = 0;
	data->window_width = 0;
	data->window_height = 0;
	data->sea = NULL;
	data->tile = NULL;
	data->berry = NULL;
	data->character_right = NULL;
	data->character_left = NULL;
	data->character = NULL;
	data->exit = NULL;
	data->mlx = NULL;
	data->window = NULL;
	data->map = NULL;
}
