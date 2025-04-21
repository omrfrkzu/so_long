/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:42 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:43 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

void	destroy_images(t_data *data)
{
	if (data->background)
		mlx_destroy_image(data->mlx, data->background);
	if (data->island)
		mlx_destroy_image(data->mlx, data->island);
	if (data->collectible)
		mlx_destroy_image(data->mlx, data->collectible);
	if (data->player_right)
		mlx_destroy_image(data->mlx, data->player_right);
	if (data->player_left)
		mlx_destroy_image(data->mlx, data->player_left);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
}

void	error_exit(t_data *data)
{
	destroy_images(data);
	if (data->screen)
		mlx_destroy_window(data->mlx, data->screen);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data);
	free(data);
	write(1, "Error\n", 6);
	exit(-1);
}

void	error(t_data *data)
{
	free(data);
	write(1, "Error\n", 6);
	exit(-1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->screen_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	clean_exit(void *game_context)
{
	t_data	*data;

	data = (t_data *)game_context;
	destroy_images(data);
	if (data->screen)
		mlx_destroy_window(data->mlx, data->screen);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	free_map(data);
	free(data);
	exit(-1);
	return (0);
}
