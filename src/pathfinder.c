/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:53:27 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/08 11:30:33 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_dfs *data, int x, int y)
{
	int		width;
	int		height;
	char	**map;

	map = data->map;
	width = data->width;
	height = data->height;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	return (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E');
}

int	dfs(t_dfs *d)
{
	int		i;
	t_dfs	new_dfs;

	if (d->x == d->goal_x && d->y == d->goal_y)
		return (1);
	if (d->map[d->y][d->x] == '1')
		return (0);
	d->map[d->y][d->x] = '1';
	i = 0;
	while (i < 4)
	{
		new_dfs = *d;
		new_dfs.x = d->x + d->directions[i][0];
		new_dfs.y = d->y + d->directions[i][1];
		if (is_valid(d, new_dfs.x, new_dfs.y) && dfs(&new_dfs))
			return (1);
		i++;
	}
	return (0);
}
