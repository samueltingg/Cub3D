/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_horizontal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:23 by etien             #+#    #+#             */
/*   Updated: 2025/01/15 21:16:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks the horizontal (left and right) edges
// for all middle rows in the map.
bool	check_horizontal_edges(t_map *map)
{
	int	left_edge_x;
	int	right_edge_x;
	int	y;

	y = -1;
	while (++y < map->map_height)
	{
		left_edge_x = get_horizontal_edge(map, y, 0, LEFT);
		right_edge_x = get_horizontal_edge(map, y,
				map->map_width - 1, RIGHT);
		if (left_edge_x < 0 || right_edge_x < 0)
			return (false);
		if (!valid_horizontal_edge(map, y, left_edge_x, LEFT)
			|| !valid_horizontal_edge(map, y, right_edge_x, RIGHT))
			return (false);
	}
	return (true);
}

// This function checks that the horizontal edge is valid:
// 1) Is not a wall
// 2) If it is a corner - has neighbours along at least one axis.
// 3) If not a corner - has vertical neighbours.
// Checks 2 and 3 ensure that there are no holes in the walls.
bool	valid_horizontal_edge(t_map *map, int y, int x, int edge_dir)
{
	int	corner_dir;

	corner_dir = is_a_corner(map, y, x, edge_dir);
	if (!is_a_wall(map, y, x))
		return (false);
	if (corner_dir == TOP || corner_dir == BOTTOM)
	{
		if (!check_horizontal_neighbours(map, y, x, corner_dir)
			&& !check_vertical_neighbours(map, y, x, edge_dir))
			return (false);
	}
	else
		if (!check_vertical_neighbours(map, y, x, edge_dir))
			return (false);
	return (true);
}

// This function will return the x-coordinate of the left/right edge.
int	get_horizontal_edge(t_map *map, int y, int x, int edge_dir)
{
	while (x >= 0 && x < map->map_width)
	{
		if (ft_strchr(WHITESPACE, map->map[y][x]))
		{
			if (edge_dir == LEFT)
				x++;
			else if (edge_dir == RIGHT)
				x--;
		}
		else
			return (x);
	}
	return (-1);
}

// This function will check the vertical neighbours of the edges in
// the middle rows. An edge needs to have two vertical neighbours
// (one top, one bottom) to be considered valid.
bool	check_vertical_neighbours(t_map *map, int y, int x, int edge_dir)
{
	t_vertical_neighbour	valid_neighbour;

	valid_neighbour.top = false;
	valid_neighbour.bottom = false;
	if (y == 0 || y == map->map_height - 1)
		return (true);
	while (map->map[y][x] == '1')
	{
		valid_vertical_neighbours(map, y, x, &valid_neighbour);
		if (valid_neighbour.top && valid_neighbour.bottom)
			return (true);
		if (edge_dir == LEFT)
			x++;
		else if (edge_dir == RIGHT)
			x--;
	}
	return (false);
}

// The vertical neighbours of an edge will be checked separately:
// Top: Either top left, top, top right is a wall
// Bottom: Either bottom left, bottom, bottom right is a wall
// Visualization where E: edge and 1: wall:
//     111 (TL, T, TR)
//      E
//     111 (BL, B, BR)
// Different logic will apply if x is on the edge of the map to prevent
// out-of-bounds access.
void	valid_vertical_neighbours(t_map *map, int y, int x,
			t_vertical_neighbour *valid_neighbour)
{
	if (x == 0)
	{
		if (map->map[y - 1][x] == '1' || map->map[y - 1][x + 1] == '1')
			valid_neighbour->top = true;
		if (map->map[y + 1][x] == '1' || map->map[y + 1][x + 1] == '1')
			valid_neighbour->bottom = true;
	}
	else if (x == map->map_width - 1)
	{
		if (map->map[y - 1][x - 1] == '1' || map->map[y - 1][x] == '1')
			valid_neighbour->top = true;
		if (map->map[y + 1][x - 1] == '1' || map->map[y + 1][x] == '1')
			valid_neighbour->bottom = true;
	}
	else
	{
		if (map->map[y - 1][x - 1] == '1' || map->map[y - 1][x] == '1'
			|| map->map[y - 1][x + 1] == '1')
			valid_neighbour->top = true;
		if (map->map[y + 1][x - 1] == '1' || map->map[y + 1][x] == '1'
			|| map->map[y + 1][x + 1] == '1')
			valid_neighbour->bottom = true;
	}
}
