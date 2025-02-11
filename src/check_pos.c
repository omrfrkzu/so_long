/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:52:33 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/11 18:15:57 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] != '1')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] != '1')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] != '1')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] != '1')
			return (1);
	}
	return (0);
}

int	check_collectible(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'C')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'C')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'C')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] == 'C')
			return (1);
	}
	return (0);
}

int	check_exit(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'E')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'E')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'E')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] == 'E')
			return (1);
	}
	return (0);
}

int	check_any_collectible(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
