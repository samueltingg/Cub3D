/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/20 16:13:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	handle_translation(int keycode, t_vars *vars)
// {
// 	double	tx;
// 	double	ty;

// 	ty = 0;
// 	tx = 0;
// 	if (keycode == KEY_D)
// 	{
// 		tx = -(1 * vars->dir_y);
// 		ty = (1 * vars->dir_x);
// 	}
// 	else if (keycode == KEY_A)
// 	{
// 		tx = (1 * vars->dir_y);
// 		ty = -(1 * vars->dir_x);
// 	}
// 	else if (keycode == KEY_W)
// 	{
// 		tx = (1 * vars->dir_x);
// 		ty = (1 * vars->dir_y);
// 	}
// 	else if (keycode == KEY_S)
// 	{
// 		tx = -(1 * vars->dir_x);
// 		ty = -(1 * vars->dir_y);
// 	}
// 	else
// 		return ;
// 	// printf("p_x: %f, p_y: %f\n", vars->p_x, vars->p_y);
// 	if (vars->map[(int)((vars->p_y + ty) / BLOCK_W)][(int)((vars->p_x + tx)
// 			/ BLOCK_H)] != '1')
// 	{
// 		vars->p_x += tx;
// 		vars->p_y += ty;
// 	}
// }

void	handle_translation(int keycode, t_data *data)
{
	double	tx;
	double	ty;

	ty = 0;
	tx = 0;
	if (keycode == KEY_D)
	{
		tx = -(0.1 * data->player.dir_y);
		ty = (0.1 * data->player.dir_x);
	}
	else if (keycode == KEY_A)
	{
		tx = (0.1 * data->player.dir_y);
		ty = -(0.1 * data->player.dir_x);
	}
	else if (keycode == KEY_W)
	{
		tx = (0.1 * data->player.dir_x);
		ty = (0.1 * data->player.dir_y);
	}
	else if (keycode == KEY_S)
	{
		tx = -(0.1 * data->player.dir_x);
		ty = -(0.1 * data->player.dir_y);
	}
	else
		return ;
	
	if (data->map[(int)(data->player.pos_y + ty)][(int)(data->player.pos_x + tx)
		] != '1')
	{
		data->player.pos_x += tx;
		data->player.pos_y += ty;
	}
}

void	multiply_dir_vec_to_rot_matrix(t_player *player, double rot_amt)
{
	// double	x;
	// double	y;

	// x = vars->dir_x;
	// y = vars->dir_y;
	// vars->dir_x = cos(rot_amt) * x - sin(rot_amt) * y;
	// vars->dir_y = sin(rot_amt) * x + cos(rot_amt) * y;

	//updated
	double old_dir_x; 
	double old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_amt) - player->dir_y * sin(rot_amt);
	player->dir_y = old_dir_x * sin(rot_amt) + player->dir_y * cos(rot_amt);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_amt) - player->plane_y * sin(rot_amt);
	player->plane_y = old_plane_x * sin(rot_amt) + player->plane_y * cos(rot_amt);
}

void	handle_rotate(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT)
		multiply_dir_vec_to_rot_matrix(player, RADIAN(-1));
	else if (keycode == KEY_RIGHT)
		multiply_dir_vec_to_rot_matrix(player, RADIAN(1));
}

int	handle_key_event(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		close_window(data);
	handle_translation(keycode, data);
	handle_rotate(keycode, &data->player);
	return (0);
}
