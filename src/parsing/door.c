/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:59:41 by etien             #+#    #+#             */
/*   Updated: 2025/01/23 23:03:40 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will set up doors for all door candidates
// by changing their map element from '1' to 'D'.
void	set_up_door(t_data	*data)
{
	int			i;
	t_coords	*candidates;
	int			candidate_count;

	i = -1;
	candidates = malloc(sizeof(t_coords)
			* (data->map_height * data->map_width));
	mark_outside_boundary(data);
	candidate_count = get_door_candidates(data, candidates);
	if (candidate_count == 0)
	{
		free(candidates);
		return ;
	}
	while (++i < candidate_count)
		data->map[(candidates[i].y)][(candidates[i].x)] = 'D';
	free(candidates);
}

// This function will store valid door candidates in the candidates array.
int	get_door_candidates(t_data *data, t_coords *candidates)
{
	int	candidate_count;
	int	y;
	int	x;

	candidate_count = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1' && !on_map_boundary(data, y, x)
				&& valid_door_candidate(data, y, x))
			{
				candidates[candidate_count].y = y;
				candidates[candidate_count].x = x;
				candidate_count++;
			}
		}
	}
	return (candidate_count);
}

// A valid door candidate must have adjacent walls along one axis
// and adjacent empty spaces along the perpendicular axis, i.e.:
//  0       1
// 1X1 and 0X0
//  0       1
bool	valid_door_candidate(t_data *data, int y, int x)
{
	if ((data->map[y - 1][x] == '1' && data->map[y + 1][x] == '1'
		&& ft_strchr(EMPTY_SPACE, data->map[y][x - 1])
		&& ft_strchr(EMPTY_SPACE, data->map[y][x + 1]))
		|| (ft_strchr(EMPTY_SPACE, data->map[y - 1][x])
		&& ft_strchr(EMPTY_SPACE, data->map[y + 1][x])
		&& data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1'))
		return (true);
	return (false);
}

// This function will call flood_fill to mark all whitespace
// coordinates outside the map boundaries with an 'X'.
void	mark_outside_boundary(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < data->map_height)
	{
		if (data->map[y][0] == ' ')
			flood_fill(data, y, 0);
		if (data->map[y][data->map_width - 1] == ' ')
			flood_fill(data, y, data->map_width - 1);
	}
	while (++x < data->map_width)
	{
		if (data->map[0][x] == ' ')
			flood_fill(data, 0, x);
		if (data->map[data->map_height - 1][x] == ' ')
			flood_fill(data, data->map_height - 1, x);
	}
}

void	flood_fill(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->map_height
		|| x < 0 || x >= data->map_width
		|| data->map[y][x] != ' ')
		return ;
	data->map[y][x] = 'X';
	flood_fill(data, y - 1, x);
	flood_fill(data, y + 1, x);
	flood_fill(data, y, x - 1);
	flood_fill(data, y, x + 1);
}
