/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:23 by etien             #+#    #+#             */
/*   Updated: 2025/01/09 18:24:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks that the left and right edge of each
// row are walls after skipping over the leading and trailing
// whitespaces.
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

// This function checks that the top and bottom rows are only composed
// of walls after trimming leading and trailing whitespaces.
bool	check_top_bottom_rows(t_map *map)
{
	char	*trimmed_top;
	char	*trimmed_bottom;

	trimmed_top = ft_strtrim(map->map[0], WHITESPACE);
	trimmed_bottom = ft_strtrim(map->map[map->map_height - 1], WHITESPACE);
	if (!only_walls(trimmed_top) || !only_walls(trimmed_bottom))
		return (free(trimmed_top), free(trimmed_bottom), false);
	return (free(trimmed_top), free(trimmed_bottom), true);
}

// This function checks that the string is composed entirely of '1's.
bool	only_walls(char *s)
{
	while (*s)
	{
		if (*s != '1')
			return (false);
		s++;
	}
	return (true);
}
