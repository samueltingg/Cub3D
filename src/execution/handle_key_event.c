/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/26 19:38:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_translation(int keycode, t_data *data, t_player *player)
{
	double	move_speed;
	double	tx;
	double	ty;

	move_speed = 0.1;
	ty = 0;
	tx = 0;
	if (keycode == KEY_D)
	{
		tx = -(move_speed * player->dir_y);
		ty = (move_speed * player->dir_x);
	}
	else if (keycode == KEY_A)
	{
		tx = (move_speed * player->dir_y);
		ty = -(move_speed * player->dir_x);
	}
	else if (keycode == KEY_W)
	{
		tx = (move_speed * player->dir_x);
		ty = (move_speed * player->dir_y);
	}
	else if (keycode == KEY_S)
	{
		tx = -(move_speed * player->dir_x);
		ty = -(move_speed * player->dir_y);
	}
	else
		return ;
	if (!ft_strchr(WALLS, data->map[(int)(player->pos_y)]
			[(int)(player->pos_x + tx)]))
		player->pos_x += tx;
	if (!ft_strchr(WALLS, data->map[(int)(player->pos_y + ty)]
			[(int)(player->pos_x)]))
		player->pos_y += ty;
}

// multiplies Player's Direction & Plane Vector individually to the rotation matrix
void	multiply_vectors_to_rot_matrix(t_player *player, double rot_amt)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_amt) - player->dir_y * sin(rot_amt);
	player->dir_y = old_dir_x * sin(rot_amt) + player->dir_y * cos(rot_amt);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_amt) - player->plane_y
		* sin(rot_amt);
	player->plane_y = old_plane_x * sin(rot_amt) + player->plane_y
		* cos(rot_amt);
}

void	handle_rotate(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT)
		multiply_vectors_to_rot_matrix(player, RADIAN(-1));
	else if (keycode == KEY_RIGHT)
		multiply_vectors_to_rot_matrix(player, RADIAN(1));
}

// If a door is already active, the keystroke is ignored and the
// function will immediately return.
void	handle_door(int keycode, t_data *data)
{
	t_ray	ray;
	if (keycode == KEY_E)
	{
		if (data->door.is_open != 0)
			return ;
		printf("Attempting to open door\n");
		if (detect_door(data, &ray))
		{
			printf("Door detected\n");
			data->door.x = ray.map_x;
			data->door.y = ray.map_y;
			data->door.is_open = 1;
			data->map[ray.map_y][ray.map_x] = '0';
		}
		else
			printf("No door here\n");
	}
}


int	handle_key_event(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		close_window(data);
	handle_translation(keycode, data, &data->player);
	handle_rotate(keycode, &data->player);
	handle_door(keycode, data);
	return (0);
}
