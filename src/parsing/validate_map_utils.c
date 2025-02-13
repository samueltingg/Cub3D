/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:32:11 by etien             #+#    #+#             */
/*   Updated: 2025/01/26 12:40:38 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will ensure that there is only one player
// in the map and store the player's direction and position.
void	store_player(t_data *data, int y, int x, int *player_count)
{
	int	c;

	c = data->map[y][x];
	if (ft_strchr(DIRECTIONS, c))
	{
		if (*player_count == 0)
		{
			store_vectors(&data->player, c);
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
void	store_vectors(t_player *player, char c)
{
	if (c == 'N')
	{
		store_dir(player, 0, -1);
		store_plane(player, 0.66, 0);
	}
	else if (c == 'S')
	{
		store_dir(player, 0, 1);
		store_plane(player, -0.66, 0);
	}
	else if (c == 'W')
	{
		store_dir(player, -1, 0);
		store_plane(player, 0, -0.66);
	}
	else if (c == 'E')
	{
		store_dir(player, 1, 0);
		store_plane(player, 0, 0.66);
	}
}

void	store_dir(t_player *player, double dir_x, double dir_y)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
}

void	store_plane(t_player *player, double plane_x, double plane_y)
{
	player->plane_x = plane_x;
	player->plane_y = plane_y;
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
