/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/22 17:44:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	validate_map(t_data *data)
{
	validate_player(data);
	validate_boundaries(data);
	// validate_textures(data);
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

// A minimum valid map would have to be at least 3x3.
void	validate_boundaries(t_data *data)
{
	if (data->map_width < 3 || data->map_height < 3)
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
	if (!check_horizontal_edges(data) || !check_vertical_edges(data))
		err_free_exit(MAP_BOUNDARIES_ERR, data, NULL);
}

// This function ensures that the texture files can be opened.
void	validate_textures(t_data *data)
{
	if (!texture_is_accessible(data->tex.north_texture)
		|| !texture_is_accessible(data->tex.south_texture)
		|| !texture_is_accessible(data->tex.west_texture)
		|| !texture_is_accessible(data->tex.east_texture))
		err_free_exit(TEXTURE_OPEN_ERR, data, NULL);
}
