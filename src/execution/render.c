/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/27 09:01:36 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_ceiling_n_floor(t_img *img, t_texture tex)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT/2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, tex.ceiling_color);
		++i;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, tex.floor_color);
		++i;
	}
}

int	render(void *param)
{
	t_data	*data;
	double	delta_time;

	data = (t_data *)param;
	delta_time = get_delta_time(data);
	if (data->win_ptr == NULL)
		return (1);
	ft_bzero(data->img.addr, WINDOW_HEIGHT * WINDOW_WIDTH * (data->img.bits_per_pixel / 8));
	render_ceiling_n_floor(&data->img, data->tex);
	update_door(&data->door, delta_time);
	raycasting(data);
	open_door_raycasting(data);
	render_minimap(data, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}
