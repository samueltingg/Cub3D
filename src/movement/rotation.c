/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuelting <samuelting@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:32 by sting             #+#    #+#             */
/*   Updated: 2025/02/14 09:12:17 by samuelting       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	radian(double angle_degrees)
{
	return (angle_degrees * PI / 180.0);
}

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

void	rotate_player(int key, t_player *player, double rotate_amt)
{
	if (key == LEFT_ARR)
		multiply_vectors_to_rot_matrix(player, radian(-rotate_amt));
	else if (key == RIGHT_ARR)
		multiply_vectors_to_rot_matrix(player, radian(rotate_amt));
	else if (key == MOUSE_MOVE_LEFT)
		multiply_vectors_to_rot_matrix(player, radian(-rotate_amt));
	else if (key == MOUSE_MOVE_RIGHT)
		multiply_vectors_to_rot_matrix(player, radian(rotate_amt));
}
