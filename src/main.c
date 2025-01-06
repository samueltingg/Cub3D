/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 15:46:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(void *params)
{
	t_vars	*vars;

	vars = (t_vars *)params;
	// mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	// free_all_cord(vars);
	exit(0);
}

void mlx(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	mlx_hook(vars->win_ptr, ON_DESTROY, 0, &close_window, vars);
	mlx_loop(vars->mlx_ptr);
}

int main(void)
{
	t_vars vars;

	mlx(&vars);
}