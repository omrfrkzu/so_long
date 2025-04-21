/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:49:08 by omkuzu            #+#    #+#             */
/*   Updated: 2025/04/20 14:45:50 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

typedef struct s_data
{
	void	*mlx;
	void	*screen;
	void	*background;
	void	*island;
	void	*collectible;
	void	*player_right;
	void	*player_left;
	void	*player;
	void	*exit;
	int		x;
	int		y;
	int		screen_width;
	int		screen_height;
	int		block_size;
	int		loop_count;
	long	step_counter;
	char	**map;
}	t_data;

typedef struct s_dfs
{
	char	**map;
	int		width;
	int		height;
	int		paths[4][2];
	int		x;
	int		y;
	int		dest_x;
	int		dest_y;
}	t_dfs;

void	init_images(t_data *data);
void	load_map(t_data *data, char *file);
void	reset_data(t_data *data);
void	init_data(t_data *data);

char	**copy_map(char **origin_map, int height, int width);
void	init_locations(t_dfs *data_dfs);
void	free_dfs(t_dfs *data);

void	destroy_images(t_data *data);
void	error_exit(t_data *data);
void	error(t_data *data);
void	free_map(t_data *data);
int		clean_exit(void *game_context);

void	key_w(t_data *data);
void	key_a(t_data *data);
void	key_s(t_data *data);
void	key_d(t_data *data);

int		is_wall_blocked(t_data *data, char move_type);
int		is_item_at_position(t_data *data, char move_type);
int		is_exit_reached(t_data *data, char move_type);
int		has_collectible(t_data *data);

void	check_reachability(t_data *data, char **map, int x, int y);
void	validate_map_paths(t_data *data);

void	checker(t_data *data, char **argv);
void	size_width_height(t_data *data, int fd);
void	filename_checker(char *str);
int		check_map(t_data *data, int start, int exit_c, int collectible);

int		check_walls(char **map, int width, int height);
void	player_pos(t_data *data);

int		depth_first_search(t_dfs *d);
int		valid_move(t_dfs *data, int x, int y);

void	image_place(t_data *data, void *image, int x, int y);
void	render_tile(t_data *data, int x, int y);
void	render_map(t_data *data);
void	render_original_block(t_data *data, int x, int y);

int		main(int argc, char **argv);
void	update_move_counter(t_data *data, int increment);
int		process_key_input(int keycode, void *game_context);

char	*ft_itoa(long n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif