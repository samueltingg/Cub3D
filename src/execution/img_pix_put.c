/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:20:23 by sting             #+#    #+#             */
/*   Updated: 2025/02/04 09:41:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
- code below uses a formula to access the memory location of
	a specific pixel coordinate(given as input) of the image.
*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * (img->line_len / 4) + x;
	img->addr[pixel] = color;
}
