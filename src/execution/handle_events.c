/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/02/06 11:59:30 by sting            ###   ########.fr       */
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
				&& data->door.progress == 1)
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


int mouse_hook(int x,int y,void *param)
{
	t_data	*data;
	int delta_x;
	int mouse_speed;

	(void)y;
	data = (t_data *)param;
	mouse_speed = 30;
	delta_x = x - (WINDOW_WIDTH / 2);
	if (delta_x > 0)
		rotate_player(MOUSE_MOVE_RIGHT, &data->player, abs(delta_x) / mouse_speed);
	else if (delta_x < 0)
		rotate_player(MOUSE_MOVE_LEFT, &data->player, abs(delta_x) / mouse_speed);

	mlx_mouse_move(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}