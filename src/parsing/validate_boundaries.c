/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_boundaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:10:17 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 14:38:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function duplicates the map for checking purposes
// and stores it in a t_map_copy struct.
t_map_copy	copy_map(char **map, int height, int width)
{
	t_map_copy	map_copy;
	char		**copied_map;
	int			y;

	map_copy.height = height;
	map_copy.width = width;
	copied_map = malloc(sizeof(char *) * (height + 1));
	copied_map[height] = 0;
	y = -1;
	while (++y < height)
		copied_map[y] = ft_strdup(map[y]);
	map_copy.map = copied_map;
	return (map_copy);
}

// This function uses the flood fill algorithm with the player's 
// position as the starting point to determine if the map has unclosed walls.
// If y or x exceeds the bounds of the maps, it will return true.
// 'V' is used to mark a tile has been visited.
bool	check_unclosed_walls(t_map_copy *map_copy, int y, int x)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (y < 0 || y >= map_copy->height || x < 0 || x >= map_copy->width)
		return (true);
	if (map_copy->map[y][x] == '1' || map_copy->map[y][x] == 'V')
		return (false);
	map_copy->map[y][x] = 'V';
	up = check_unclosed_walls(map_copy, y - 1, x);
	down = check_unclosed_walls(map_copy, y + 1, x);
	left = check_unclosed_walls(map_copy, y, x - 1);
	right = check_unclosed_walls(map_copy, y, x + 1);
	return (up || down || left || right);
}

// This function checks if a coordinate is on the map's boundary 
// (i.e. adjacent to an 'X').
bool	on_map_boundary(t_data *data, int y, int x)
{
	if (y == 0 || y == data->map_height || x == 0 || x == data->map_width)
		return (true);
	else if (data->map[y - 1][x] == 'X' || data->map[y + 1][x] == 'X'
		|| data->map[y][x - 1] == 'X' || data->map[y][x + 1] == 'X')
		return (true);
	return (false);
}
