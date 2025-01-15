/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:10:17 by etien             #+#    #+#             */
/*   Updated: 2025/01/15 21:11:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks if the coordinate is a wall (i.e. '1').
bool	is_a_wall(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1')
		return (false);
	return (true);
}

// A corner is a coordinate that is both a horizontal edge and a vertical edge.
// The function will return the corresponding corner edge.
int	is_a_corner(t_map *map, int y, int x, int edge_dir)
{
	if (edge_dir == LEFT || edge_dir == RIGHT)
	{
		if (y == get_vertical_edge(map, 0, x, TOP))
			return (TOP);
		else if (y == get_vertical_edge(map, map->map_height - 1,
				x, BOTTOM))
			return (BOTTOM);
	}
	else if (edge_dir == TOP || edge_dir == BOTTOM)
	{
		if (x == get_horizontal_edge(map, y, 0, LEFT))
			return (LEFT);
		else if (x == get_horizontal_edge(map, y,
				map->map_width - 1, RIGHT))
			return (RIGHT);
	}
	return (-1);
}
