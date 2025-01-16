/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/16 16:17:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_translation(int keycode, t_vars *vars)
{
	double	tx;
	double	ty;

	ty = 0;
	tx = 0;
	if (keycode == KEY_D)
	{
		tx = -(1 * vars->dir_y);
		ty = (1 * vars->dir_x);
	}
	else if (keycode == KEY_A)
	{
		tx = (1 * vars->dir_y);
		ty = -(1 * vars->dir_x);
	}
	else if (keycode == KEY_W)
	{
		tx = (1 * vars->dir_x);
		ty = (1 * vars->dir_y);
	}
	else if (keycode == KEY_S)
	{
		tx = -(1 * vars->dir_x);
		ty = -(1 * vars->dir_y);
	}
	else
		return ;
	// printf("p_x: %f, p_y: %f\n", vars->p_x, vars->p_y);
	if (vars->map[(int)((vars->p_y + ty) / BLOCK_W)][(int)((vars->p_x + tx)
			/ BLOCK_H)] != '1')
	{
		vars->p_x += tx;
		vars->p_y += ty;
	}
}

void	multiply_dir_vec_to_rot_matrix(t_vars *vars, double rot_amt)
{
	double	x;
	double	y;

	;
	x = vars->dir_x;
	y = vars->dir_y;
	vars->dir_x = cos(rot_amt) * x - sin(rot_amt) * y;
	vars->dir_y = sin(rot_amt) * x + cos(rot_amt) * y;
}

void	handle_rotate(int keycode, t_vars *vars)
{
	if (keycode == KEY_LEFT)
		multiply_dir_vec_to_rot_matrix(vars, RADIAN(-1));
	else if (keycode == KEY_RIGHT)
		multiply_dir_vec_to_rot_matrix(vars, RADIAN(1));
}

int	handle_key_event(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == KEY_ESC)
		close_window(vars);
	handle_translation(keycode, vars);
	handle_rotate(keycode, vars);
	return (0);
}
