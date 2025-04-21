/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:49:00 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/20 15:20:07 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	depth_first_search(t_dfs *d)
{
	int		i;
	t_dfs	next;

	if (d->x == d->dest_x && d->y == d->dest_y)
		return (1);
	if (d->map[d->y][d->x] == '1')
		return (0);
	d->map[d->y][d->x] = '1';
	i = 0;
	while (i < 4)
	{
		next = *d;
		next.x = d->x + d->paths[i][0];
		next.y = d->y + d->paths[i][1];
		if (valid_move(d, next.x, next.y) && depth_first_search(&next))
			return (1);
		i++;
	}
	return (0);
}

int	valid_move(t_dfs *d, int x, int y)
{
	if (x < 0 || y < 0 || x >= d->width || y >= d->height)
		return (0);
	if (d->map[y][x] == '1')
		return (0);
	return (1);
}
