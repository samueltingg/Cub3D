/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 14:32:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	validate_map(t_data *data)
{
	validate_player(data);
	validate_boundaries(data);
	validate_textures(data);
	set_up_door(data);
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

// This function validates the map boundaries by checking that the 
// map is at least 3x3 and does not have unclosed walls.
void	validate_boundaries(t_data *data)
{
	t_map_copy	map_copy;

	if (data->map_width < 3 || data->map_height < 3)
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
	map_copy = copy_map(data->map, data->map_height, data->map_width);
	if (check_unclosed_walls(&map_copy, data->player.pos_y, data->player.pos_x))
	{
		free_double_arr(map_copy.map);
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
	}
	free_double_arr(map_copy.map);
}

// This function ensures that the texture files can be opened.
void	validate_textures(t_data *data)
{
	if (!texture_is_accessible(data->tex.path[0])
		|| !texture_is_accessible(data->tex.path[1])
		|| !texture_is_accessible(data->tex.path[2])
		|| !texture_is_accessible(data->tex.path[3]))
		err_free_exit(TEXTURE_OPEN_ERR, data, NULL);
}
