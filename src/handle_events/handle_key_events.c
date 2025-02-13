/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuelting <samuelting@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/02/13 18:32:05 by samuelting       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// If a door is already active, the keystroke is ignored and the
// function will immediately return.
void	handle_door(int keycode, t_data *data)
{
	t_ray	ray;

	if (keycode == KEY_E)
	{
		if (detect_door(data, &ray))
		{
			printf("Door detected\n");
			if (data->door.is_open == 0)
			{
				data->door.x = ray.map_x;
				data->door.y = ray.map_y;
				data->door.is_open = 1;
			}
			else if (ray.map_x == data->door.x && ray.map_y == data->door.y
				&& data->door.progress == FULLY_OPEN)
				data->door.is_open = -1;
		}
		else
			printf("No door here\n");
	}
}

int	handle_key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		data->keys[W] = TRUE;
	else if (keycode == KEY_A)
		data->keys[A] = TRUE;
	else if (keycode == KEY_S)
		data->keys[S] = TRUE;
	else if (keycode == KEY_D)
		data->keys[D] = TRUE;
	else if (keycode == KEY_LEFT)
		data->keys[LEFT_ARR] = TRUE;
	else if (keycode == KEY_RIGHT)
		data->keys[RIGHT_ARR] = TRUE;
	handle_door(keycode, data);
	return (0);
}

int	handle_key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_W)
		data->keys[W] = FALSE;
	else if (keycode == KEY_A)
		data->keys[A] = FALSE;
	else if (keycode == KEY_S)
		data->keys[S] = FALSE;
	else if (keycode == KEY_D)
		data->keys[D] = FALSE;
	else if (keycode == KEY_LEFT)
		data->keys[LEFT_ARR] = FALSE;
	else if (keycode == KEY_RIGHT)
		data->keys[RIGHT_ARR] = FALSE;
	return (0);
}
