/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:47:33 by etien             #+#    #+#             */
/*   Updated: 2025/01/03 14:39:58 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void print_err(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		print_err();
	// if check_extension()
	// {
	// 	print_err()
	// }

	return (0);
}


// bool check_extension()
// {

// }


