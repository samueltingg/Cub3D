/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:04:56 by etien             #+#    #+#             */
/*   Updated: 2025/01/27 12:36:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function detects for doors within a range of one unit distance
// in front of the player. The detection is done with DDA.
// WINDOW_WIDTH / 2 corresponds to the middle of the screen
bool	detect_door(t_data *data, t_ray *ray)
{
	double	distance;

	ft_bzero(ray, sizeof(t_ray));
	init_raycasting_info(WINDOW_WIDTH / 2, ray, data->player);
	dda_setup(ray, data->player);
	perform_dda(ray, data, DOOR_DETECTION);
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

// This function updates the door_progress and toggles the is_open
// state of the door.
// is_open can take three values:
// 0 - door is closed
// 1 - door is opening
// -1 - door is closing
void	update_door_variables(t_data *data, t_door *door, double delta_time)
{
	if (door->is_open == 0)
		return ;
	else if (door->is_open == 1)
	{
		door->progress += delta_time * 0.5;
		if (door->progress >= 1.0)
		{
			door->progress = 1.0;
			door->time_elapsed += delta_time;
		}
	}
	else if (door->is_open == -1)
	{
		door->progress -= delta_time * 0.5;
		if (door->progress <= 0.0)
			door_init(door);
	}
	close_door_automatically(data, door);
}

// This function will set the door to start closing if the door has been
// open for 2 seconds and the player is at least one unit distance away.
void	close_door_automatically(t_data *data, t_door *door)
{
	double	distance;

	distance = 0;
	if (door->time_elapsed >= 2.0)
	{
		distance = pow(data->player.pos_x - door->x, 2)
			+ pow(data->player.pos_y - door->y, 2);
		if (distance >= 1.0)
			door->is_open = -1;
	}
}

// This function is called in render_textures to add a vertical
// offset to the ray->draw_start and ray->draw_end of the sliding door
// that will scale with door_progress. The starting texture position
// will also be offset so that the texture to wall mapping remains consistent.
void	add_door_offset(t_data *data, t_ray *ray, t_texture *tex, double step)
{
	int		horizon;
	double	vertical_offset;
	double	progress;

	horizon = WINDOW_HEIGHT / 2;
	vertical_offset = 0;
	progress = data->door.progress;
	if (ray->map_x != data->door.x || ray->map_y != data->door.y)
		return ;
	vertical_offset = -ray->line_height * progress;
	ray->draw_start = horizon - ray->line_height / 2 + vertical_offset;
	ray->draw_end = horizon + ray->line_height / 2 + vertical_offset;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_start >= WINDOW_HEIGHT)
		ray->draw_start = WINDOW_HEIGHT - 1;
	tex->pos = (ray->draw_start - horizon + ray->line_height / 2) * step;
	tex->pos += tex->img[tex->dir].height * progress;
}

// This function is similar to the raycasting function but modified to
// render the sliding animation of the interacted door.
void	open_door_raycasting(t_data *data)
{
	int		win_x;
	t_ray	ray;

	win_x = -1;
	while (++win_x < WINDOW_WIDTH)
	{
		init_raycasting_info(win_x, &ray, data->player);
		dda_setup(&ray, data->player);
		perform_dda(&ray, data, OPEN_DOOR);
		if (ray.map_y == data->door.y && ray.map_x == data->door.x)
		{
			calc_line_height(&ray);
			render_textures(data, ray, data->tex, win_x);
		}
	}
}
