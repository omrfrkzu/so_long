/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:29 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/20 15:18:09 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	load_image(t_data *data, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!*img)
		error_exit(data);
}

void	init_images(t_data *data)
{
	load_image(data, (void **)&data->background, "images/bg.xpm");
	load_image(data, (void **)&data->island, "images/island.xpm");
	load_image(data, (void **)&data->player_right, "images/player.xpm");
	load_image(data, (void **)&data->player_left, "images/playerrev.xpm");
	load_image(data, (void **)&data->collectible, "images/collectible.xpm");
	load_image(data, (void **)&data->exit, "images/exit.xpm");
}

void	load_map(t_data *data, char *file)
{
	int		fd;
	char	*row;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(data);
	i = 0;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		data->map[i] = row;
		i++;
	}
	close(fd);
}

void	reset_data(t_data *data)
{
	data->loop_count = 0;
	data->step_counter = 0;
	data->screen_width = 0;
	data->screen_height = 0;
	data->background = NULL;
	data->island = NULL;
	data->collectible = NULL;
	data->player_right = NULL;
	data->player_left = NULL;
	data->player = NULL;
	data->exit = NULL;
	data->mlx = NULL;
	data->screen = NULL;
	data->map = NULL;
}

void	init_data(t_data *data)
{
	data->block_size = 100;
	if (data->screen_width == 0 || data->screen_height == 0)
		error(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(data);
	data->screen = mlx_new_window(data->mlx, data->screen_width * 100,
			data->screen_height * 100, "so_long");
	if (!data->screen)
		error_exit(data);
	init_images(data);
	data->player = data->player_right;
}
