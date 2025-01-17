/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:12:33 by sting             #+#    #+#             */
/*   Updated: 2025/01/17 15:13:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "parsing.h"

typedef struct s_cord
{
	double				x;
	double				y;
	double				z;
	int					color;
}						t_cord;

// /**
//  * @param line_len amount of bytes taken by one row of our image
//  * @param img_ptr pointer to the image structure created by mlx_new_image
//  * @param addr pointer to the raw pixel data of the image
//  */
// typedef struct s_img
// {
// 	void				*img_ptr;
// 	char				*addr;
// 	int					bits_per_pixel;
// 	int					line_len;
// 	int					endian;
// }						t_img;

typedef struct s_line_cord
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color1;
	int					color2;
}						t_line_cord;

typedef struct s_line_var
{
	int					dx;
	int					dy;
	int					d;
	int					x;
	int					y;
	int					xi;
	int					yi;
}						t_line_var;

typedef struct s_angle
{
	double				x;
	double				y;
	double				z;
}						t_angle;

// -------Newly added--------

typedef struct s_rect
{
	double x; // origin (top left)
	double y; // origin (top left)
	double				width;
	double				height;
	int					color;
}						t_rect;
//---------------------------

typedef struct s_vars
{
	char				**map;
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;

	// coordinate of player
	double				p_x;
	double				p_y;

	// raycasting section
	double				dir_x;
	double				dir_y;
	double				p_angle;
	double				plane_x;
	double				plane_y;

}						t_vars;


// * RENDERING
void					img_pix_put(t_img *img, int x, int y, int color);
void					render_background(t_img *img, int color);
int						render(void *param);
void					render_square(t_img *img, t_rect rect);
void					render_map(t_vars *vars, char **map);
void					render_grid_lines(t_img *img, int map_width,
							int map_height);

// * RAYCASTING
void					render_rays(t_vars *vars);

// BRESENHAM'S LINE ALGO
void					render_line_bresenham(t_img *img, t_line_cord cord);
void					render_line_low(t_img *img, t_line_cord line);

// * COLOR
int						gradient(int startcolor, int endcolor, int len,
							int pix);

// Handle Key Event
int						close_window(void *params);
int						handle_key_event(int keycode, void *param);
void					raycasting(t_vars *vars);

#endif