/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:46:05 by etien             #+#    #+#             */
/*   Updated: 2025/01/06 19:53:10 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strtrim_mod(char *s1, char const *set)
{
	char *trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	free(s1);
	return (trimmed_str);
}

void	skip_characters(char *characters, char **s)
{
	while (ft_strchr(characters, **s))
		(*s)++;
}

