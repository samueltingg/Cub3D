/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/16 10:21:32 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	handle_translation(int keycode, t_vars *vars)
{
	int	tx;
	int	ty;

	ty = 0;
	tx = 0;
	if (keycode == KEY_D)
		tx = 10;
	else if (keycode == KEY_A)
		tx = -10;
	else if (keycode == KEY_W)
		ty = -10;
	else if (keycode == KEY_S)
		ty = 10;
	else
		return ;
	vars->p_x += tx;
	vars->p_y += ty;
}

void multiply_dir_vec_to_rot_matrix(t_vars *vars, double rot_amt)
{
	double x;
	double y;;

	x = vars->dir_x;
	y = vars->dir_y;
	vars->dir_x = cos(rot_amt) * x - sin(rot_amt) * y;
	vars->dir_y = sin(rot_amt) * x + cos(rot_amt) * y;
}

void	handle_rotate(int keycode, t_vars *vars)
{
	if (keycode == KEY_LEFT)
		multiply_dir_vec_to_rot_matrix(vars, RADIAN(-10));
	else if(keycode == KEY_RIGHT)
		multiply_dir_vec_to_rot_matrix(vars, RADIAN(10));
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
