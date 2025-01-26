/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:04:56 by etien             #+#    #+#             */
/*   Updated: 2025/01/26 19:24:32 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// WINDOW_WIDTH / 2 corresponds to the middle of the screen
bool	detect_door(t_data *data, t_ray *ray)
{
	double	distance;

	ft_bzero(ray, sizeof(t_ray));
	init_raycasting_info(WINDOW_WIDTH / 2, ray, data->player);
	dda_setup(ray, data->player);
	perform_dda(ray, data);
	if (data->map[ray->map_y][ray->map_x] == 'D')
	{
		if (ray->side == EW)
			distance = (ray->side_dist_x - ray->delta_dist_x);
		else if (ray->side == NS)
			distance = (ray->side_dist_y - ray->delta_dist_y);
		return (distance <= 1.01);
	}
	return (false);
}

// is_open can take three values:
// 0 - door is closed
// 1 - door is opening
// -1 - door is closing
void	update_door(t_door *door, double delta_time)
{
	if (door->is_open == 0)
		return ;
	else if (door->is_open == 1)
	{
		door->progress += delta_time;
		if (door->progress >= 1.0)
		{
			door->progress = 1.0;
			door->is_open = -1;
		}
	}
	else if (door->is_open == -1)
	{
		door->progress -= delta_time;
		if (door->progress <= 0.0)
		{
			door_init(door);
			printf("Door closed\n");
		}
	}
}

double	get_delta_time(t_data	*data)
{
	struct timeval	current_time;
	double			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - data->last_time.tv_sec) +
		(current_time.tv_usec - data->last_time.tv_usec) / 1e6;
	data->last_time = current_time;
	return (delta_time);
}
