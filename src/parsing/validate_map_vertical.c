/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_vertical.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:30:03 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 14:14:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks the vertical (top and bottom) edges
// for all middle columns in the map.
bool	check_vertical_edges(t_data *data)
{
	int	top_edge_y;
	int	bottom_edge_y;
	int	x;

	x = -1;
	while (++x < data->map_width)
	{
		top_edge_y = get_vertical_edge(data, 0, x, TOP);
		bottom_edge_y = get_vertical_edge(data, data->map_height - 1,
				x, BOTTOM);
		if (top_edge_y < 0 || bottom_edge_y < 0)
			return (false);
		if (!valid_vertical_edge(data, top_edge_y, x, TOP)
			|| !valid_vertical_edge(data, bottom_edge_y, x, BOTTOM))
			return (false);
	}
	return (true);
}

// This function checks that the vertical edge is valid:
// 1) Is not a wall
// 2) If it is a corner - has neighbours along at least one axis.
// 3) If not a corner - has horizontal neighbours.
// Checks 2 and 3 ensure that there are no holes in the walls.
bool	valid_vertical_edge(t_data *data, int y, int x, int edge_dir)
{
	int	corner_dir;

	corner_dir = is_a_corner(data, y, x, edge_dir);
	if (!is_a_wall(data, y, x))
		return (false);
	if (corner_dir == LEFT || corner_dir == RIGHT)
	{
		if (!check_vertical_neighbours(data, y, x, corner_dir)
			&& !check_horizontal_neighbours(data, y, x, edge_dir))
			return (false);
	}
	else
		if (!check_horizontal_neighbours(data, y, x, edge_dir))
			return (false);
	return (true);
}

// This function will return the y-coordinate of the top/bottom edge.
// It works in a similar way to get_horizontal_edge() but is adapted
// for column traversal. If the return value is -1, it means that the
// column is composed entirely of spaces, hence invalid (similar
// treatment as empty line in the map).
int	get_vertical_edge(t_data *data, int y, int x, int edge_dir)
{
	while (y >= 0 && y < data->map_height)
	{
		if (ft_strchr(WHITESPACE, data->map[y][x]))
		{
			if (edge_dir == TOP)
				y++;
			else if (edge_dir == BOTTOM)
				y--;
		}
		else
			return (y);
	}
	return (-1);
}

// This function will check the horizontal neighbours of the edges in
// the middle rows. An edge needs to have two horizontal neighbours
// (one left, one right) to be considered valid.
bool	check_horizontal_neighbours(t_data *data, int y, int x, int edge_dir)
{
	t_horizontal_neighbour	valid_neighbour;

	valid_neighbour.left = false;
	valid_neighbour.right = false;
	if (x == 0 || x == data->map_width - 1)
		return (true);
	while (data->map[y][x] == '1')
	{
		valid_horizontal_neighbours(data, y, x, &valid_neighbour);
		if (valid_neighbour.left && valid_neighbour.right)
			return (true);
		if (edge_dir == TOP)
			y++;
		else if (edge_dir == BOTTOM)
			y--;
	}
	return (false);
}

// The horizontal neighbours of an edge will be checked separately:
// Left: Either top left, left, top left is a wall
// Right: Either top right, right, bottom right is a wall
// Visualization where E: edge and 1: wall:
//     1 1 (TL, TR)
//     1E1 (L, R)
//     1 1 (BL, BR)
// Different logic will apply if y is on the edge of the map to prevent
// out-of-bounds access.
void	valid_horizontal_neighbours(t_data *data, int y, int x,
			t_horizontal_neighbour *valid_neighbour)
{
	if (y == 0)
	{
		if (data->map[y][x - 1] == '1' || data->map[y + 1][x - 1] == '1')
			valid_neighbour->left = true;
		if (data->map[y][x + 1] == '1' || data->map[y + 1][x + 1] == '1')
			valid_neighbour->right = true;
	}
	else if (y == data->map_height - 1)
	{
		if (data->map[y - 1][x - 1] == '1' || data->map[y][x - 1] == '1')
			valid_neighbour->left = true;
		if (data->map[y - 1][x + 1] == '1' || data->map[y][x + 1] == '1')
			valid_neighbour->right = true;
	}
	else
	{
		if (data->map[y - 1][x - 1] == '1' || data->map[y][x - 1] == '1'
			|| data->map[y + 1][x - 1] == '1')
			valid_neighbour->left = true;
		if (data->map[y - 1][x + 1] == '1' || data->map[y][x + 1] == '1'
			|| data->map[y + 1][x + 1] == '1')
			valid_neighbour->right = true;
	}
}
