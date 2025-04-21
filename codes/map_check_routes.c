/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_routes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:52 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:53 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	check_reachability(t_data *data, char **map, int x, int y)
{
	t_dfs	*data_dfs;

	data_dfs = malloc(sizeof(t_dfs));
	if (!data_dfs)
		error_exit(data);
	init_locations(data_dfs);
	data_dfs->map = copy_map(map, data->screen_height, data->screen_width);
	data_dfs->width = data->screen_width;
	data_dfs->height = data->screen_height;
	data_dfs->x = data->x;
	data_dfs->y = data->y;
	data_dfs->dest_x = x;
	data_dfs->dest_y = y;
	if (!depth_first_search(data_dfs))
	{
		free_dfs(data_dfs);
		error_exit(data);
	}
	else
		free_dfs(data_dfs);
}

void	validate_map_paths(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			if (data->map[y][x] == 'C')
				check_reachability(data, data->map, x, y);
			if (data->map[y][x] == 'E')
				check_reachability(data, data->map, x, y);
			x++;
		}
		y++;
	}
}
