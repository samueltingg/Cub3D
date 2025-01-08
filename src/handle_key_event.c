/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/08 10:51:50 by sting            ###   ########.fr       */
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


int	handle_key_event(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == KEY_ESC)
		close_window(vars);
	// else if (keycode == KEY_R)
	// {
	// 	reset_grid(vars);
	// 	if (vars->flags.split_4_view == TRUE)
	// 		free_all_splitview_cord(vars);
	// 	vars->flags.split_4_view = FALSE;
	// }
	// else if (vars->flags.split_4_view == TRUE)
	// 	return (0);
	// else if (keycode == KEY_PLUS)
	// 	vars->gap++;
	// else if (keycode == KEY_MINUS && vars->gap - 1 > 0)
	// 	vars->gap--;
	handle_translation(keycode, vars);
	// handle_rotate(keycode, vars);
	// if_other_key_pressed(keycode, vars);
	return (0);
}
