/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:25 by abinti-a          #+#    #+#             */
/*   Updated: 2024/12/02 10:39:58 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief strcmp() function lexicographically compare the null-terminated
 * strings s1 and s2.
 * compared.
 * @return The strcmp() function return an integer greater
 * than, equal to, or less than 0, according as the string s1 is greater
 * than, equal to, or less than the string s2.  The comparison is done
 * using unsigned characters, so that `\200' is greater than `\0'.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	const char s1[] = " ";
// 	const char s2[] = "";
// 	printf("ori: %d\n", strcmp(s1, s2));
// 	printf("mine: %d\n", ft_strcmp(s1,s2));
// 	return (0);
// }
