/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_horizontal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:23 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 18:44:57 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks that the left and right edge of each
// row are walls after skipping over the leading and trailing
// whitespaces. It will then check that the edges in the middle
// rows have vertical neighbours to ensure that there are no holes
// in the walls.
bool	check_left_right_edge(t_map *map)
{
	char	*left_edge;
	char	*right_edge;
	int		y;

	y = -1;
	while (map->map[++y])
	{
		left_edge = map->map[y];
		right_edge = map->map[y];
		skip_whitespace(&left_edge);
		skip_whitespace_rev(&right_edge);
		if (*left_edge != '1' || *right_edge != '1')
			return (false);
		if (!check_vertical_neighbours(map, left_edge, y, LEFT)
			|| !check_vertical_neighbours(map, right_edge, y, RIGHT))
			return (false);
	}
	return (true);
}

// This function will check the vertical neighbours of the edges in
// the middle rows. An edge needs to have two vertical neighbours
// (one top, one bottom) to be considered valid.
bool	check_vertical_neighbours(t_map *map, char *edge, int y, int dir)
{
	int	valid_neighbours;
	int	x;

	valid_neighbours = 0;
	x = edge - map->map[y];
	if (y == 0 || y == map->map_height - 1)
		return (true);
	while (map->map[y][x] == '1')
	{
		valid_vertical_neighbours(map, y, x, &valid_neighbours);
		if (valid_neighbours == 2)
			return (true);
		if (dir == LEFT)
			x++;
		else if (dir == RIGHT)
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
			int *valid_neighbours)
{
	if (x == 0)
	{
		if (map->map[y - 1][x] == '1' || map->map[y - 1][x + 1] == '1')
			*valid_neighbours += 1;
		if (map->map[y + 1][x] == '1' || map->map[y + 1][x + 1] == '1')
			*valid_neighbours += 1;
	}
	else if (x == map->map_width - 1)
	{
		if (map->map[y - 1][x - 1] == '1' || map->map[y - 1][x] == '1')
			*valid_neighbours += 1;
		if (map->map[y + 1][x - 1] == '1' || map->map[y + 1][x] == '1')
			*valid_neighbours += 1;
	}
	else
	{
		if (map->map[y - 1][x - 1] == '1' || map->map[y - 1][x] == '1'
			|| map->map[y - 1][x + 1] == '1')
			*valid_neighbours += 1;
		if (map->map[y + 1][x - 1] == '1' || map->map[y + 1][x] == '1'
			|| map->map[y + 1][x + 1] == '1')
			*valid_neighbours += 1;
	}
}

