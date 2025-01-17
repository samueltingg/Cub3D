/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 11:00:06 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	validate_map(t_map *map)
{
	validate_player(map);
	validate_boundaries(map);
}

// This function will validate the player.
// The program will terminate if there is no player in the map.
void	validate_player(t_map *map)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			store_player(map, y, x, &player_count);
	}
	if (player_count == 0)
		err_free_exit(PLAYER_MISSING_ERR, map, NULL);
}

// This function will ensure that there is only one player
// in the map and store the player's direction and position.
void	store_player(t_map *map, int y, int x, int *player_count)
{
	if (ft_strchr(DIRECTIONS, map->map[y][x]))
	{
		if (*player_count == 0)
		{
			store_dir_vector(map, map->map[y][x]);
			map->pos_x = x;
			map->pos_y = y;
			(*player_count)++;
		}
		else
			err_free_exit(PLAYER_COUNT_ERR, map, NULL);
	}
}

// This function will translate the player's starting direction
// to its x and y direction vectors.
void	store_dir_vector(t_map *map, char c)
{
	if (c == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
	}
	else if (c == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
	}
	else if (c == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
	}
	else if (c == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
	}
}

// A minimum valid map would have to be at least 3x3.
void	validate_boundaries(t_map *map)
{
	if (map->map_width < 3 || map->map_height < 3)
		err_free_exit(MAP_BOUNDARIES_ERR, map, NULL);
	if (!check_horizontal_edges(map) || !check_vertical_edges(map))
		err_free_exit(MAP_BOUNDARIES_ERR, map, NULL);
}
