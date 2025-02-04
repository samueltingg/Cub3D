/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/02/04 09:43:58 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
