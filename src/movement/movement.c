/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:50:16 by sting             #+#    #+#             */
/*   Updated: 2025/02/14 09:10:18 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_movement(t_data *data, bool *keys, t_player *player)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (keys[i] == TRUE)
		{
			if (i > 3)
				rotate_player(i, player, 0.5);
			else
				translate_player(i, data, player);
		}
	}
}
