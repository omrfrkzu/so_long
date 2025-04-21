/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:55 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/20 15:19:01 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

void	checker(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data);
	size_width_height(data, fd);
	close(fd);
	data->map = malloc(sizeof(char *) * data->screen_height);
	if (!data->map)
		error(data);
	load_map(data, argv[1]);
	if (!check_map(data, 0, 0, 0))
		error_exit(data);
	player_pos(data);
	validate_map_paths(data);
	if (!check_walls(data->map, data->screen_width, data->screen_height))
		error_exit(data);
}

void	size_width_height(t_data *data, int fd)
{
	char	*row;
	int		flag;
	int		len;

	flag = 0;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		len = ft_strlen(row);
		data->screen_height++;
		if (data->screen_width == 0)
			data->screen_width = len;
		else if (data->screen_width != len)
			flag = 1;
		free(row);
	}
	if (flag)
		error(data);
	close(fd);
}

void	filename_checker(char *filename)
{
	int	len;

	if (!filename)
		error(NULL);
	len = ft_strlen(filename);
	if (len < 5)
		error(NULL);
	if (filename[len - 1] != 'r'
		|| filename[len - 2] != 'e'
		|| filename[len - 3] != 'b'
		|| filename[len - 4] != '.')
		error(NULL);
	if (filename[len - 5] == '/' || filename[len - 5] == '\0')
		error(NULL);
}

int	check_map(t_data *data, int start, int exit_c, int collectible)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			tile = data->map[y][x];
			if (tile == 'P')
				start++;
			else if (tile == 'E')
				exit_c++;
			else if (tile == 'C')
				collectible++;
			else if (tile != '1' && tile != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (start == 1 && exit_c == 1 && collectible > 0);
}
