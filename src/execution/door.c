/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:04:56 by etien             #+#    #+#             */
/*   Updated: 2025/01/26 18:03:38 by etien            ###   ########.fr       */
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
		return (distance <= 1);
	}
	return (false);
}




