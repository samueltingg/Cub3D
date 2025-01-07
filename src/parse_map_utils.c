/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:26 by etien             #+#    #+#             */
/*   Updated: 2025/01/07 11:12:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will detect for the map by skipping over
// whitespace and checking that the first character is one
// of the map elements.
bool	detect_map(char *line)
{
	char	*s;

	s = line;
	skip_characters(WHITESPACE, &s);
	if (ft_strchr(MAP_ELEMENTS, *s))
		return (true);
	else
		return (false);
}
