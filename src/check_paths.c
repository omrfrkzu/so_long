/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:52:26 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/07 19:52:28 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	check_paths(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'C')
				create_find(data, data->map, x, y);
			if (data->map[y][x] == 'E')
				create_find(data, data->map, x, y);
			x++;
		}
		y++;
	}
}

void	create_find(t_data *data, char **map, int x, int y)
{
	t_dfs	*data_dfs;

	data_dfs = malloc(sizeof(t_dfs));
	if (!data_dfs)
		error_exit(data);
	set_directions(data_dfs);
	data_dfs->map = copy_map(map, data->window_height, data->window_width);
	data_dfs->width = data->window_width;
	data_dfs->height = data->window_height;
	data_dfs->x = data->x;
	data_dfs->y = data->y;
	data_dfs->goal_x = x;
	data_dfs->goal_y = y;
	if (!dfs(data_dfs))
	{
		free_dfs(data_dfs);
		error_exit(data);
	}
	else
		free_dfs(data_dfs);
}
