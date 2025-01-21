/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2025/01/21 13:54:22 by sting            ###   ########.fr       */
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

	data = (t_data *)param;
	if (data->win_ptr == NULL)
		return (1);
	ft_bzero(data->img.addr, WINDOW_HEIGHT * WINDOW_WIDTH * (data->img.bits_per_pixel / 8));
	// render_half_background(&data->img, data->tex.ceiling_color);
	render_ceiling_n_floor(&data->img, data->tex);
	raycasting(data);
	render_minimap(data, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}
