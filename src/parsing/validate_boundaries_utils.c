/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_boundaries_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:10:17 by etien             #+#    #+#             */
/*   Updated: 2025/01/23 22:57:38 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks if the coordinate is a wall (i.e. '1').
bool	is_a_wall(t_data *data, int y, int x)
{
	if (data->map[y][x] != '1')
		return (false);
	return (true);
}

// A corner is a coordinate that is both a horizontal edge and a vertical edge.
// The function will return the corresponding corner edge.
int	is_a_corner(t_data *data, int y, int x, int edge_dir)
{
	if (edge_dir == LEFT || edge_dir == RIGHT)
	{
		if (y == get_vertical_edge(data, 0, x, TOP))
			return (TOP);
		else if (y == get_vertical_edge(data, data->map_height - 1,
				x, BOTTOM))
			return (BOTTOM);
	}
	else if (edge_dir == TOP || edge_dir == BOTTOM)
	{
		if (x == get_horizontal_edge(data, y, 0, LEFT))
			return (LEFT);
		else if (x == get_horizontal_edge(data, y,
				data->map_width - 1, RIGHT))
			return (RIGHT);
	}
	return (-1);
}

// This function checks if a coordinate is on the map's boundary by
// comparing its coordinates with the edge coordinates on both of
// its axes. If a coordinate is neither a horizonal nor vertical edge,
// it may still be on the boundary if it is adjacent to an 'X'.
bool	on_map_boundary(t_data *data, int y, int x)
{
	if (y == get_vertical_edge(data, 0, x, TOP)
		|| y == get_vertical_edge(data, data->map_height - 1, x, BOTTOM)
		|| x == get_horizontal_edge(data, y, 0, LEFT)
		|| x == get_horizontal_edge(data, y, data->map_width - 1, RIGHT))
		return (true);
	else if (data->map[y - 1][x] == 'X' || data->map[y + 1][x] == 'X'
		|| data->map[y][x - 1] == 'X' || data->map[y][x + 1] == 'X')
		return (true);
	return (false);
}
