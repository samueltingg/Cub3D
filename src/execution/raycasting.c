/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:57 by sting             #+#    #+#             */
/*   Updated: 2025/01/24 16:38:52 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
	"ray->delta_dist_x = 1e30; ""
	avoid division of 0, hence set to high value
*/
void	init_raycasting_info(int x, t_ray *ray, t_player player)
{
	// calculate ray position & direction based on x cordinate of screen
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	// x-coordinate in camera space
	ray->dir_x = player.dir_x + (player.plane_x * ray->camera_x);
	ray->dir_y = player.dir_y + (player.plane_y * ray->camera_x);
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

// calculate step & initial side dist
void	dda_setup(t_ray *ray, t_player player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player.pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_data *data)
{
	while (1)
	{
		// jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = EW;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = NS;
		}
		// Check if ray has hit a wall
		if (data->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
void	calc_line_height(t_ray *ray)
{
	if (ray->side == EW)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else if (ray->side == NS)
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->perp_wall_dist < (double)1)
		// to avoid division of close to 0 number during calc of line_height
		ray->perp_wall_dist = 1;
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
}

void	raycasting(t_data *data)
{
	int		win_x;
	t_ray	ray;

	win_x = -1;
	while (++win_x < WINDOW_WIDTH)
	{
		init_raycasting_info(win_x, &ray, data->player);
		dda_setup(&ray, data->player);
		perform_dda(&ray, data);
		calc_line_height(&ray);
		render_textures(data, ray, data->tex, win_x);
	}
}
// render_line_bresenham(&data->img, (t_line_cord){win_x, ray.draw_start, win_x,
// 	ray.draw_end, color, color});
