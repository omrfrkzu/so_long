/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:52:58 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/07 19:53:00 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	map_walls(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
