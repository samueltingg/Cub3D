/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:35:23 by sting             #+#    #+#             */
/*   Updated: 2025/01/17 11:47:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "macros.h"
# include "mlx.h"
# include "../libft/libft/libft.h"
# include "parsing.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	double	pos_x; //parsing
	double	pos_y; //parsing
	double	dir_x; //parsing
	double	dir_y; //parsing
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_texture
{ // parsing (all below)
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color
}	t_texture;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_ray		*ray;
	t_player	*player; //parsing
	t_texture	*tex; //parsing
	char		**map; //parsing
	int			map_height; //parsing
	int			map_width; //parsing
}	t_data;

#endif
