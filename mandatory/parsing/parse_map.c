/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:58:41 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:29:54 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_coordinate_begin_end(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->map[i][j])
	{
		if (data->map->map[i][j] != 'D' && data->map->map[i][j] != '1')
			error_file("error\nmap border are not close");
		j++;
	}
	while (data->map->map[i + 1])
		i++;
	j = 0;
	while (data->map->map[i][j])
	{
		if (data->map->map[i][j] != 'D' && data->map->map[i][j] != '1')
			error_file("Error\nmap border are not close");
		j++;
	}
}

static void	check_coordinate_map_elem_and_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] != '0' && data->map->map[i][j] != '1' &&
				data->map->map[i][j] != 'D' && data->map->map[i][j] != 'W' &&
				data->map->map[i][j] != 'E' && data->map->map[i][j] != 'N' &&
				data->map->map[i][j] != 'S')
				error_file("Error\nuse of a different elem in the map");
			else if (data->map->map[i][j] == 'E' || data->map->map[i][j] == 'W' \
			|| data->map->map[i][j] == 'S' || data->map->map[i][j] == 'N')
			{
				if (data->map->player)
					error_file("Error\none player only accepted no more");
				data->map->player = data->map->map[i][j];
			}
			j++;
		}
		i++;
	}
}

static void	check_map_error_helper(t_data *data, int i, int *j)
{
	while (data->map->map[i][(*j) + 1])
	{
		if (data->map->map[i][(*j)] == '0' || data->map->map[i][(*j)] == 'W' ||
			data->map->map[i][(*j)] == 'E' || data->map->map[i][(*j)] == 'S' ||
			data->map->map[i][(*j)] == 'N')
		{
			if (data->map->map[i - 1][(*j)] == 'D' || \
					data->map->map[i + 1][(*j)] == 'D' || \
					data->map->map[i][(*j) - 1] == 'D' || \
					data->map->map[i][(*j) + 1] == 'D')
				error_file("Error\nmap coordinate not close");
		}
		(*j)++;
	}
}

void	check_map_error(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	check_coordinate_map_elem_and_player(data);
	if (!data->map->player)
		error_file("Error\nthe player not exist");
	check_coordinate_begin_end(data);
	while (data->map->map[i])
	{
		j = 1;
		if (data->map->map[i][0] != 'D' && data->map->map[i][0] != '1')
			error_file("Error\nmap border are not close");
		check_map_error_helper(data, i, &j);
		if (data->map->map[i][j] != 'D' && data->map->map[i][j] != '1')
			error_file("Error\nmap border are not close with 1");
		i++;
	}
}
