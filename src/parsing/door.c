/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:59:41 by etien             #+#    #+#             */
/*   Updated: 2025/01/22 17:59:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_up_door(t_data	*data)
{
	t_coords	candidates[data->map_height * data->map_width];
	int			i;
	int			candidate_count;

	i = -1;
	candidate_count = get_door_candidates(data, candidates);
	if (candidate_count == 0)
		return ;
	else
	{
		while (++i < candidate_count)
		{
			data->map[(candidates[i].y)][(candidates[i].x)] = '2';
		}
	}
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
		printf("y: %d\n", y);
		x = -1;
		while (data->map[y][++x])
		{
			printf("Checking tile y=%d, x=%d\n", y, x);
			if (is_an_edge(data, y, x))
				printf("Tile y=%d, x=%d is incorrectly marked as an edge.\n", y, x);
			if (data->map[y][x] == '1' && !is_an_edge(data, y, x)
				&& valid_door_candidate(data, y, x))
			{
				candidates[candidate_count].y = y;
				candidates[candidate_count].x = x;
				candidate_count++;
			}
		}
	}
	printf("Candidate count: %d\n",candidate_count);
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


