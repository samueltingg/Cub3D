/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/17 14:56:10 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(void *params)
{
	t_vars	*vars;

	vars = (t_vars *)params;
	mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	// free_all_cord(vars);
	exit(0);
}

void init_vars(t_vars *vars)
{
	vars->p_x = 2; // tmp
	vars->p_y = 5; // tmp

	vars->dir_x = 1;
	vars->dir_y = 0;
	vars->plane_x = 0;
	vars->plane_y = 0.66;
}

void mlx(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D");
	vars->img.img_ptr = mlx_new_image(vars->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	mlx_loop_hook(vars->mlx_ptr, &render, vars);
	mlx_hook(vars->win_ptr, ON_KEYDOWN, 1L << 0, &handle_key_event, vars);
	mlx_hook(vars->win_ptr, ON_DESTROY, 0, &close_window, vars);
	mlx_loop(vars->mlx_ptr);
}

int main(void)
{
	char	*eg_map[] = {
		"1111111",
		"1001001",
		"1001001",
		"1001001",
		"1000N01",
		"1000001",
		"1111111",
		NULL};
	t_vars vars;

	vars.map = eg_map; // ! example map
	init_vars(&vars);	
	mlx(&vars);
	
}
