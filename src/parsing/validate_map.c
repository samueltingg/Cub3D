/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/20 15:40:17 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	validate_map(t_data *data)
{
	validate_player(data);
	validate_boundaries(data);
}

// This function will validate the player.
// The program will terminate if there is no player in the map.
void	validate_player(t_data *data)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			store_player(data, y, x, &player_count);
	}
	if (player_count == 0)
		err_free_exit(PLAYER_MISSING_ERR, data, NULL);
}

// This function will ensure that there is only one player
// in the map and store the player's direction and position.
void	store_player(t_data *data, int y, int x, int *player_count)
{
	if (ft_strchr(DIRECTIONS, data->map[y][x]))
	{
		if (*player_count == 0)
		{
			store_dir_vector(&data->player, data->map[y][x]);
			data->player.pos_x = x;
			data->player.pos_y = y;
			(*player_count)++;
		}
		else
			err_free_exit(PLAYER_COUNT_ERR, data, NULL);
	}
}

// This function will translate the player's starting direction
// to its x and y direction vectors.
void	store_dir_vector(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

// A minimum valid map would have to be at least 3x3.
void	validate_boundaries(t_data *data)
{
	if (data->map_width < 3 || data->map_height < 3)
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
	if (!check_horizontal_edges(data) || !check_vertical_edges(data))
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
}
