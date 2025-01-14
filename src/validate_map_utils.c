/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:10:17 by etien             #+#    #+#             */
/*   Updated: 2025/01/14 19:17:13 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks if the coordinate is a wall (i.e. '1').
bool	is_a_wall(t_map *map, int y, int x, int edge_dir)
{
	if (map->map[y][x] != '1')
	{
		print_unclosed_map(map, y, x, edge_dir);
		return (false);
	}
	return (true);
}

// A corner is a coordinate that is both a horizontal edge and a vertical edge.
bool	is_a_corner(t_map *map, int y, int x, int edge_dir)
{
	int	top_edge_y;
	int	bottom_edge_y;
	int	left_edge_x;
	int	right_edge_x;

	if (edge_dir == LEFT || edge_dir == RIGHT)
	{
		top_edge_y = get_top_bottom_edge(map, 0, x, TOP);
		bottom_edge_y = get_top_bottom_edge(map, map->map_height - 1,
				x, BOTTOM);
		if (y == top_edge_y || y == bottom_edge_y)
			return (true);
	}
	else if (edge_dir == TOP || edge_dir == BOTTOM)
	{
		left_edge_x = get_left_right_edge(map, y, 0, LEFT);
		right_edge_x = get_left_right_edge(map, y,
				map->map_width - 1, RIGHT);
		if (x == left_edge_x || x == right_edge_x)
			return (true);
	}
	return (false);
}
