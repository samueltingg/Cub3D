/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:00:34 by sting             #+#    #+#             */
/*   Updated: 2025/02/06 15:04:33 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_translation_vector(int key, t_player *player, double *tx,
		double *ty)
{
	*tx = 0;
	*ty = 0;
	if (key == D)
	{
		*tx = -(0.1 * player->dir_y);
		*ty = (0.1 * player->dir_x);
	}
	else if (key == A)
	{
		*tx = (0.1 * player->dir_y);
		*ty = -(0.1 * player->dir_x);
	}
	else if (key == W)
	{
		*tx = (0.1 * player->dir_x);
		*ty = (0.1 * player->dir_y);
	}
	else if (key == S)
	{
		*tx = -(0.1 * player->dir_x);
		*ty = -(0.1 * player->dir_y);
	}
}

void	calculate_gap(double tx, double ty, double *gap_x, double *gap_y)
{
	double	buffer;
	double	length;

	buffer = 0.3;
	length = sqrt(tx * tx + ty * ty);
	*gap_x = (tx / length) * buffer;
	*gap_y = (ty / length) * buffer;
}

bool	can_move(t_data *data, double new_x, double new_y)
{
	return (((int)new_y == data->door.y && (int)new_x == data->door.x
			&& data->door.progress == FULLY_OPEN) || !ft_strchr(OBSTACLE,
			data->map[(int)new_y][(int)new_x]));
}

void	translate_player(int key, t_data *data, t_player *player)
{
	double	tx;
	double	ty;
	double	gap_x;
	double	gap_y;

	get_translation_vector(key, player, &tx, &ty);
	calculate_gap(tx, ty, &gap_x, &gap_y);
	if (can_move(data, player->pos_x + tx + gap_x, player->pos_y))
		player->pos_x += tx;
	if (can_move(data, player->pos_x, player->pos_y + ty + gap_y))
		player->pos_y += ty;
}
