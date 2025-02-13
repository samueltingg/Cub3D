/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:12:37 by sting             #+#    #+#             */
/*   Updated: 2025/02/05 16:41:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gradient(int start_color, int end_color, int len, int position)
{
	double	increment[3];
	int		new[3];
	int		new_color;

	increment[0] = (double)((end_color >> 16) - (start_color >> 16))
		/ (double)len;
	increment[1] = (double)(((end_color >> 8) & 0xFF)
			- ((start_color >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((end_color & 0xFF) - (start_color & 0xFF))
		/ (double)len;
	new[0] = (start_color >> 16) + round(position * increment[0]);
	new[1] = ((start_color >> 8) & 0xFF) + round(position * increment[1]);
	new[2] = (start_color & 0xFF) + round(position * increment[2]);
	new_color = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_color);
}
