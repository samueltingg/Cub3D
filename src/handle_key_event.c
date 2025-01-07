/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:06 by sting             #+#    #+#             */
/*   Updated: 2025/01/07 15:32:05 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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
	// handle_translation(keycode, vars);
	// handle_rotate(keycode, vars);
	// if_other_key_pressed(keycode, vars);
	return (0);
}