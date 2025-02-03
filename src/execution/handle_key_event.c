/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/02/03 15:00:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	handle_translation(int keycode, t_data *data, t_player *player)
// {
// 	double	move_speed;
// 	double	tx;
// 	double	ty;

// 	move_speed = 0.1;
// 	ty = 0;
// 	tx = 0;
// 	if (keycode == KEY_D)
// 	{
// 		tx = -(move_speed * player->dir_y);
// 		ty = (move_speed * player->dir_x);
// 	}
// 	else if (keycode == KEY_A)
// 	{
// 		tx = (move_speed * player->dir_y);
// 		ty = -(move_speed * player->dir_x);
// 	}
// 	else if (keycode == KEY_W)
// 	{
// 		tx = (move_speed * player->dir_x);
// 		ty = (move_speed * player->dir_y);
// 	}
// 	else if (keycode == KEY_S)
// 	{
// 		tx = -(move_speed * player->dir_x);
// 		ty = -(move_speed * player->dir_y);
// 	}
// 	else
// 		return ;
// 	if (data->map[(int)(player->pos_y)][(int)(player->pos_x
// 			+ tx)] != '1')
// 		player->pos_x += tx;
// 	if (data->map[(int)(player->pos_y
// 			+ ty)][(int)(player->pos_x)] != '1')
// 		player->pos_y += ty;
// }

// // multiplies Player's Direction & Plane Vector individually to the rotation matrix
// void	multiply_vectors_to_rot_matrix(t_player *player, double rot_amt)
// {
// 	double	old_dir_x;
// 	double	old_plane_x;

// 	old_dir_x = player->dir_x;
// 	player->dir_x = player->dir_x * cos(rot_amt) - player->dir_y * sin(rot_amt);
// 	player->dir_y = old_dir_x * sin(rot_amt) + player->dir_y * cos(rot_amt);
// 	old_plane_x = player->plane_x;
// 	player->plane_x = player->plane_x * cos(rot_amt) - player->plane_y
// 		* sin(rot_amt);
// 	player->plane_y = old_plane_x * sin(rot_amt) + player->plane_y
// 		* cos(rot_amt);
// }

// void	handle_rotate(int keycode, t_player *player)
// {
// 	if (keycode == KEY_LEFT)
// 		multiply_vectors_to_rot_matrix(player, RADIAN(-1));
// 	else if (keycode == KEY_RIGHT)
// 		multiply_vectors_to_rot_matrix(player, RADIAN(1));
// }

// int	handle_key_press(int keycode, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (keycode == KEY_ESC)
// 		close_window(data);
// 	handle_translation(keycode, data, &data->player);
// 	handle_rotate(keycode, &data->player);
// 	return (0);
// }

