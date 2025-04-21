/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:49:05 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/21 13:27:42 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

void	update_move_counter(t_data *data, int increment)
{
	char	*move_count_str;
	int		len;

	data->step_counter += increment;
	move_count_str = ft_itoa(data->step_counter);
	render_original_block(data, 0, 0);
	render_original_block(data, 1, 0);
	mlx_string_put(data->mlx, data->screen, 20, 50, 0xFFFFFF, move_count_str);
	len = 0;
	while (move_count_str[len] != '\0')
		len++;
	write(1, move_count_str, len);
	write(1, "\n", 1);
	free(move_count_str);
}

int	process_key_input(int keycode, void *game_context)
{
	t_data	*data;

	data = (t_data *)game_context;
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 119 && is_wall_blocked(data, 'w'))
		key_w(data);
	else if (keycode == 97)
		key_a(data);
	else if (keycode == 115 && is_wall_blocked(data, 's'))
		key_s(data);
	else if (keycode == 100)
		key_d(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error(NULL);
	filename_checker(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		error(NULL);
	reset_data(data);
	checker(data, argv);
	init_data(data);
	render_map(data);
	update_move_counter(data, 0);
	mlx_hook(data->screen, 17, 1L << 0, clean_exit, data);
	mlx_key_hook(data->screen, process_key_input, data);
	mlx_loop(data->mlx);
	return (0);
}
