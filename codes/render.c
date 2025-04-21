/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:49:03 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/20 14:44:45 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"

void	image_place(t_data *data, void *image, int x, int y)
{
	x *= data->block_size;
	y *= data->block_size;
	mlx_put_image_to_window(data->mlx, data->screen, image, x, y);
}

void	render_tile(t_data *data, int x, int y)
{
	char	tile;

	tile = data->map[y][x];
	if (tile == '1')
		image_place(data, data->background, x, y);
	else if (tile == '0')
		image_place(data, data->island, x, y);
	else if (tile == 'C')
		image_place(data, data->collectible, x, y);
	else if (tile == 'E')
		image_place(data, data->exit, x, y);
	else if (tile == 'P')
	{
		image_place(data, data->player, x, y);
		data->x = x;
		data->y = y;
		data->map[y][x] = '0';
	}
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			render_tile(data, x, y);
			x++;
		}
		y++;
	}
}

void	render_original_block(t_data *data, int x, int y)
{
	char	tile;

	tile = data->map[y][x];
	if (tile == '1')
		image_place(data, data->background, x, y);
	else
		image_place(data, data->island, x, y);
	if (tile == 'C')
		image_place(data, data->collectible, x, y);
	else if (tile == 'E')
		image_place(data, data->exit, x, y);
}
