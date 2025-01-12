/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:46:05 by etien             #+#    #+#             */
/*   Updated: 2025/01/12 17:04:32 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// A wrapper function for ft_strtrim to free the input string.
char	*ft_strtrim_mod(char *s1, char const *set)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	free(s1);
	return (trimmed_str);
}

// A helper function for skipping over leading whitespace.
void	skip_whitespace(char **s)
{
	while (**s && ft_strchr(WHITESPACE, **s))
		(*s)++;
}

// The content deletion function for clearing a t_list.
void	del(void *content)
{
	free(content);
}
