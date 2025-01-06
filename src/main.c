/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 10:38:33 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	ft_printf("hello\n");
}

// int	closee(t_vars *vars)
// {
// 	// if (keycode == )
// 	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
// 	return (0);
// }


// int	main(void)
// {
// 	t_vars vars;

// 	vars.mlx_ptr = mlx_init();
// 	if (vars.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "first window");
// 	if (vars.win_ptr == NULL)
// 	{
// 		free(vars.win_ptr);
// 		return (MLX_ERROR);
// 	}
	
// 	mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0x00FF0000);

// 	mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, closee, &vars);
// 	mlx_loop(vars.mlx_ptr);

// 	// exit loop if no window left 
// 	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
//     free(vars.mlx_ptr);
// }


