/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:50:16 by sting             #+#    #+#             */
/*   Updated: 2025/02/03 15:21:25 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int handle_key_press(int keycode, void *param)
{
	t_data *data;

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


int handle_key_release(int keycode, void *param)
{
	t_data *data;

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

void	translate_player(int keycode, t_data *data, t_player *player)
{
	double	move_speed;
	double	tx;
	double	ty;

	move_speed = 0.1;
	ty = 0;
	tx = 0;
	if (keycode == D)
	{
		tx = -(move_speed * player->dir_y);
		ty = (move_speed * player->dir_x);
	}
	else if (keycode == A)
	{
		tx = (move_speed * player->dir_y);
		ty = -(move_speed * player->dir_x);
	}
	else if (keycode == W)
	{
		tx = (move_speed * player->dir_x);
		ty = (move_speed * player->dir_y);
	}
	else if (keycode == S)
	{
		tx = -(move_speed * player->dir_x);
		ty = -(move_speed * player->dir_y);
	}
	else
		return ;
	if (data->map[(int)(player->pos_y)][(int)(player->pos_x
			+ tx)] != '1')
		player->pos_x += tx;
	if (data->map[(int)(player->pos_y
			+ ty)][(int)(player->pos_x)] != '1')
		player->pos_y += ty;
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

void	rotate_player(int keycode, t_player *player)
{
	if (keycode == LEFT_ARR)
		multiply_vectors_to_rot_matrix(player, RADIAN(-2));
	else if (keycode == RIGHT_ARR)
		multiply_vectors_to_rot_matrix(player, RADIAN(2));
}

void player_movement(t_data *data, bool *keys, t_player *player)
{
    int i;

    i = -1;
    while (++i < 6)
    {
        if (keys[i] == TRUE)
        {
            if (i > 3)
                rotate_player(i, player);
            else
                translate_player(i, data, player);
        }
    }
}