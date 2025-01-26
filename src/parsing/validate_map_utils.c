/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:32:11 by etien             #+#    #+#             */
/*   Updated: 2025/01/22 13:32:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

// This function checks whether the texture file can be opened.
bool	texture_is_accessible(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}
