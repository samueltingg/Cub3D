/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 13:58:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parse_map(char *line, t_map *map)
{
	char	*s;

	s = line;
	if (!check_completeness(map, 0))
		err_free_exit(MAP_ORDER_ERR, map, line);
	skip_characters(WHITESPACE, &s);
	if (!*s)
		err_free_exit(MAP_LINE_ERR, map, line);
}
