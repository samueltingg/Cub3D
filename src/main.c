/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/23 14:19:19 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->tex.img.img_ptr); // ! tmp
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// free_all_cord(vars);
	exit(0);
}

void init_vars(t_vars *vars)
{
	vars->p_x = 2; // tmp
	vars->p_y = 5; // tmp

	vars->dir_x = -1;
	vars->dir_y = 0;
	vars->plane_x = 0;
	vars->plane_y = -0.66;
}

// ! tmp
void init_textures(t_data *data, t_texture *tex)
{
	
	char	*relative_path = "./textures/East.xpm";
	
	tex->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &tex->width, &tex->height);
    if (tex->img.img_ptr == NULL)
    {
        fprintf(stderr, "Error: Failed to load texture from %s.\n", relative_path);
        exit(EXIT_FAILURE);
    }   
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr,
			&tex->img.bits_per_pixel, &tex->img.line_len, &tex->img.endian);
}

void mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	init_textures(data, &data->tex); // ! tmp
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, ON_KEYDOWN, 1L << 0, &handle_key_event, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, &close_window, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		err_free_exit(ARGS_ERR, NULL, NULL);
	data_init(&data);
	parse_cub(av[1], &data);
	validate_map(&data);
	print_map_data(&data);
	mlx(&data);
	free_data(&data);
	return (0);
}
