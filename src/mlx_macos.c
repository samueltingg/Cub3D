/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/02/07 16:23:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	init_textures(data, &data->tex);
	mlx_mouse_hide();
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, ON_KEYPRESS, KEYPRESS_MASK, &handle_key_press,
		data);
	mlx_hook(data->win_ptr, ON_KEYRELEASE, KEYRELEASE_MASK, &handle_key_release,
		data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, &close_window, data);
	mlx_hook(data->win_ptr, 6, 64, &mouse_hook, data);
	mlx_mouse_hook(data->win_ptr, &handle_mouse_click, data);
	mlx_loop(data->mlx_ptr);
}
