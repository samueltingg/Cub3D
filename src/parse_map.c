/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:21:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	parse_map(char *line, t_map *map)
{
	char	*s;

	s = line;
	if (
	skip_characters(WHITESPACE, &s);
	if (!*s)
		err_and_exit(EMPTY_LINE_ERR);


}
