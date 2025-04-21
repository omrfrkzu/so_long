/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:44 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:45 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_data *data)
{
	update_move_counter(data, 1);
	if (is_item_at_position(data, 'w'))
		data->map[data->y - 1][data->x] = '0';
	if (is_exit_reached(data, 'w') && has_collectible(data) == 0)
		clean_exit(data);
	render_original_block(data, data->x, data->y);
	data->y--;
	image_place(data, data->player, data->x, data->y);
}

void	key_a(t_data *data)
{
	if (!(is_wall_blocked(data, 'a')))
	{
		data->player = data->player_left;
		image_place(data, data->player, data->x, data->y);
		return ;
	}
	update_move_counter(data, 1);
	if (is_item_at_position(data, 'a'))
		data->map[data->y][data->x - 1] = '0';
	if (is_exit_reached(data, 'a') && has_collectible(data) == 0)
		clean_exit(data);
	render_original_block(data, data->x, data->y);
	data->x--;
	data->player = data->player_left;
	image_place(data, data->player, data->x, data->y);
}

void	key_s(t_data *data)
{
	update_move_counter(data, 1);
	if (is_item_at_position(data, 's'))
		data->map[data->y + 1][data->x] = '0';
	if (is_exit_reached(data, 's') && has_collectible(data) == 0)
		clean_exit(data);
	render_original_block(data, data->x, data->y);
	data->y++;
	image_place(data, data->player, data->x, data->y);
}

void	key_d(t_data *data)
{
	if (!(is_wall_blocked(data, 'd')))
	{
		data->player = data->player_right;
		image_place(data, data->player, data->x, data->y);
		return ;
	}
	update_move_counter(data, 1);
	if (is_item_at_position(data, 'd'))
		data->map[data->y][data->x + 1] = '0';
	if (is_exit_reached(data, 'd') && has_collectible(data) == 0)
		clean_exit(data);
	render_original_block(data, data->x, data->y);
	data->x++;
	data->player = data->player_right;
	image_place(data, data->player, data->x, data->y);
}
