/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:12:37 by sting             #+#    #+#             */
/*   Updated: 2025/01/27 11:30:01 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gradient(int startcolor, int endcolor, int len, int position)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor)))
		/ (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor)))
		/ (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor)))
		/ (double)len;
	new[0] = (R(startcolor)) + round(position * increment[0]);
	new[1] = (G(startcolor)) + round(position * increment[1]);
	new[2] = (B(startcolor)) + round(position * increment[2]);
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}
