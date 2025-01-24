/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/24 16:38:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_texture_imgs(t_data *data, t_img *img)
{
	int i;

	i = -1;
	while (++i < 4)
		if (img[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, img[i].img_ptr);
}

int	close_window(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	free_texture_imgs(data, data->tex.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void init_textures(t_data *data, t_texture *tex)
{
	char *path[4] = {
		"./textures/North.xpm",
		"./textures/South.xpm",
		"./textures/West.xpm",
		"./textures/East.xpm",
	};

	int i;

	i = -1;
	while (++i < 4)
	{
		tex->img[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path[i], &tex->img[i].width, &tex->img[i].height);
		if (tex->img[i].img_ptr == NULL)
		{
			printf("Error: Failed to load texture from %s.\n", path[i]);
			exit(EXIT_FAILURE);
		}   
		tex->img[i].addr = (int *)mlx_get_data_addr(tex->img[i].img_ptr,
				&tex->img[i].bits_per_pixel, &tex->img[i].line_len, &tex->img[i].endian);
	}
}

void mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img_ptr,
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
