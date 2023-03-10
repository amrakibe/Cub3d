/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:12 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:32:08 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	error_alloc(void)
{
	write(2, "Fatal: error in memory allocation\n", 34);
	exit(1);
}

void	error_file(char *msg)
{
	while (*msg)
		write(2, &*msg++, 1);
	exit(1);
}
