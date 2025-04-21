/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:48:39 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/18 19:48:40 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	**copy_map(char **origin_map, int height, int width)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc(height * sizeof(char *));
	if (!copy_map)
		return (NULL);
	while (i < height)
	{
		copy_map[i] = malloc((width + 1) * sizeof(char));
		if (!copy_map[i])
			return (NULL);
		ft_strlcpy(copy_map[i], origin_map[i], width + 1);
		i++;
	}
	return (copy_map);
}

void	init_locations(t_dfs *data_dfs)
{
	data_dfs->paths[0][0] = -1;
	data_dfs->paths[0][1] = 0;
	data_dfs->paths[1][0] = 1;
	data_dfs->paths[1][1] = 0;
	data_dfs->paths[2][0] = 0;
	data_dfs->paths[2][1] = -1;
	data_dfs->paths[3][0] = 0;
	data_dfs->paths[3][1] = 1;
}

void	free_dfs(t_dfs *data)
{
	int	c;

	c = 0;
	while (c < data->height)
	{
		free(data->map[c]);
		c++;
	}
	free(data->map);
	free(data);
}
