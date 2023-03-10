/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:50:01 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:29:13 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		init_data(&data, av[1]);
		read_file(&data);
		parse_file(&data);
		window_init(&data);
	}
	else
		error_file("Invalid argument.");
	return (0);
}
