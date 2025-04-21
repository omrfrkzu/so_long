/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:47 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:48 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall_blocked(t_data *data, char move_type)
{
	if (move_type == 'd')
	{
		if (data->map[data->y][data->x + 1] != '1')
			return (1);
	}
	else if (move_type == 'a')
	{
		if (data->map[data->y][data->x - 1] != '1')
			return (1);
	}
	else if (move_type == 'w')
	{
		if (data->map[data->y - 1][data->x] != '1')
			return (1);
	}
	else if (move_type == 's')
	{
		if (data->map[data->y + 1][data->x] != '1')
			return (1);
	}
	return (0);
}

int	is_item_at_position(t_data *data, char move_type)
{
	if (move_type == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'C')
			return (1);
	}
	else if (move_type == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'C')
			return (1);
	}
	else if (move_type == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'C')
			return (1);
	}
	else if (move_type == 's')
	{
		if (data->map[data->y + 1][data->x] == 'C')
			return (1);
	}
	return (0);
}

int	is_exit_reached(t_data *data, char move_type)
{
	if (move_type == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'E')
			return (1);
	}
	else if (move_type == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'E')
			return (1);
	}
	else if (move_type == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'E')
			return (1);
	}
	else if (move_type == 's')
	{
		if (data->map[data->y + 1][data->x] == 'E')
			return (1);
	}
	return (0);
}

int	has_collectible(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			if (data->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
