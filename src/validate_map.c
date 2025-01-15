/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/15 21:26:04 by etien            ###   ########.fr       */
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
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			store_player(map, y, x);
	}
	if (map->player_dir < 0)
		err_free_exit(PLAYER_MISSING_ERR, map, NULL);
}

// This function will ensure that there is only one player
// in the map and store the player's direction and position.
void	store_player(t_map *map, int y, int x)
{
	if (ft_strchr(DIRECTIONS, map->map[y][x]))
	{
		if (map->player_dir < 0)
		{
			if (map->map[y][x] == 'N')
				map->player_dir = NORTH;
			if (map->map[y][x] == 'S')
				map->player_dir = SOUTH;
			if (map->map[y][x] == 'W')
				map->player_dir = WEST;
			if (map->map[y][x] == 'E')
				map->player_dir = EAST;
			map->player_x = x;
			map->player_y = y;
		}
		else
			err_free_exit(PLAYER_COUNT_ERR, map, NULL);
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
