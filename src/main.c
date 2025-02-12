/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:53:22 by omkuzu            #+#    #+#             */
/*   Updated: 2025/02/12 18:59:41 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		expected_exit(data);
	else if (keycode == 119 && check_wall(data, 'w'))
		key_w(data);
	else if (keycode == 97)
		key_a(data);
	else if (keycode == 115 && check_wall(data, 's'))
		key_s(data);
	else if (keycode == 100)
		key_d(data);
	return (0);
}

void	counter(t_data *data, int plus)
{
	char	*itoa;

	data->move_counter += plus;
	itoa = ft_itoa(data->move_counter);
	draw_original_block(data, 0, 0);
	draw_original_block(data, 1, 0);
	mlx_string_put(data->mlx, data->window, 50, 50, 0x000000, itoa);
	printf("Moves: %s\n", itoa);
	free(itoa);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		err(NULL);
	filename_checker(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		err(NULL);
	init_null(data);
	checker(data, argv);
	init_data(data);
	draw_map(data);
	counter(data, 0);
	mlx_hook(data->window, 17, 0, expected_exit, data);
	mlx_key_hook(data->window, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
