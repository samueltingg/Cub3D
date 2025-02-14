/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_events_linux.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuelting <samuelting@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:12 by samuelting        #+#    #+#             */
/*   Updated: 2025/02/13 18:18:15 by samuelting       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(int x, int y, void *param)
{
	t_data	*data;
	int		delta_x;
	int		mouse_speed;

	(void)y;
	data = (t_data *)param;
	if (data->mouse_movement_flag == FALSE)
		return (0);
	mouse_speed = 30;
	delta_x = x - (WINDOW_WIDTH / 2);
	if (delta_x > 0)
		rotate_player(MOUSE_MOVE_RIGHT, &data->player, abs(delta_x)
			/ mouse_speed);
	else if (delta_x < 0)
		rotate_player(MOUSE_MOVE_LEFT, &data->player, abs(delta_x)
			/ mouse_speed);
	mlx_mouse_move(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT
		/ 2);
	return (0);
}

int	handle_mouse_click(int keycode, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (keycode == MOUSE_CLICK)
	{
		if (data->mouse_movement_flag == TRUE)
		{
			printf("Mouse Movement Turned OFF\n");
			data->mouse_movement_flag = FALSE;
			mlx_mouse_show(data->mlx_ptr, data->win_ptr);
		}
		else
		{
			printf("Mouse Movement Turned ON\n");
			data->mouse_movement_flag = TRUE;
			mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
		}
	}
	return (0);
}
