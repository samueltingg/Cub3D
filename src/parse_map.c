/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:29 by etien             #+#    #+#             */
/*   Updated: 2025/01/08 15:55:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Store extracted map lines in a temporary linked list.
void	parse_map_line(char *line, t_list **tmp, t_map *map)
{
	t_list	*node;

	if (!check_completeness(map, 0))
		err_free_exit(MAP_ORDER_ERR, map, line);
	node = malloc(sizeof(t_list));
	node->content = ft_strdup(line);
	node->next = NULL;
	ft_lstadd_back(tmp, node);
}

// void	parse_map(t_list **tmp, t_map *map)
// {

// }

void	parse_map(t_list **tmp, t_map *map)
{
	(void) map;
	remove_trailing_empty_lines(tmp);
	while (*tmp)
	{
		printf("%s", (char *)(*tmp)->content);
		*tmp = (*tmp)->next;
	}
}
