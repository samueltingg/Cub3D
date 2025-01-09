/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_vertical.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:30:03 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 19:25:50 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks that the left and right edge of each
// row are walls after skipping over the leading and trailing
// whitespaces. It will then check that the edges in the middle
// rows have vertical neighbours to ensure that there are no holes
// in the walls.
bool	check_top_bottom_edge(t_map *map)
{
	if (!check_top_edge(map))
		return (false);
	if (!check_bottom_edge(map))
		return (false);


	x = -1;
	while (map->map[++x])
	{
		if (*top_edge != '1' || *bottom_edge != '1')
			return (false);
		if (!check_horizontal_neighbours(map, top_edge, y, LEFT)
			|| !check_horizontal_neighbours(map, bottom_edge, y, RIGHT))
			return (false);
	}
	return (true);
}


bool	check_top_edge(t_map *map)
{
	char	*top_edge;
	int		top_right_x;

	top_edge = map->map[0][0];
	skip_whitespace(&top_edge);





}



bool	check_bottom_edge(t_map *map)
{
	int		y;
	int		x;
	char	*bottom_edge;
	int		bottom_right_x;

	y = map->map_height - 1;
	bottom_edge = map->map[y][0];
	skip_whitespace_rev(&bottom_edge);
	while (map->map[][])


}

// This function will check the horizontal neighbours of the edges in
// the middle rows. An edge needs to have two horizontal neighbours
// (one top, one bottom) to be considered valid.
bool	check_horizontal_neighbours(t_map *map, char *edge, int y, int dir)
{
	int	valid_neighbours;
	int	x;

	valid_neighbours = 0;
	x = edge - map->map[y];
	if (y == 0 || y == map->map_height - 1)
		return (true);
	while (map->map[y][x] == '1')
	{
		valid_horizontal_neighbours(map, y, x, &valid_neighbours);
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
void	valid_horizontal_neighbours(t_map *map, int y, int x,
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


// // This function checks that the top and bottom rows are only composed
// // of walls after trimming leading and trailing whitespaces.
// bool	check_top_bottom_rows(t_map *map)
// {
// 	char	*trimmed_top;
// 	char	*trimmed_bottom;

// 	trimmed_top = ft_strtrim(map->map[0], WHITESPACE);
// 	trimmed_bottom = ft_strtrim(map->map[map->map_height - 1], WHITESPACE);
// 	if (!only_walls(trimmed_top) || !only_walls(trimmed_bottom))
// 		return (free(trimmed_top), free(trimmed_bottom), false);
// 	return (free(trimmed_top), free(trimmed_bottom), true);
// }

// // This function checks that the string is composed entirely of '1's.
// bool	only_walls(char *s)
// {
// 	while (*s)
// 	{
// 		if (*s != '1')
// 			return (false);
// 		s++;
// 	}
// 	return (true);
// }
