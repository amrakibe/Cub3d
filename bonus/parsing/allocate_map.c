/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:15 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:31:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static int	check_if_line_exist(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i])
		return (0);
	return (1);
}

static void	check_if_other_line_exist(int i, char **map)
{
	while (map[i])
	{
		if (check_if_line_exist(map[i]))
			error_file("Error:\nMap have an empty line");
		i++;
	}
}

static void	cpy_map(t_data *data, char *map, char *line)
{
	int	i;

	i = 0;
	while (i < data->map->width)
	{
		if (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			map[i] = 'D';
		else if (!line[i])
		{
			while (i < data->map->width)
				map[i++] = 'D';
		}
		else
			map[i] = line[i];
		i++;
	}
}

static void	allocate_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	data->map->map = allocation(data, data->map->height + 1, sizeof(char *));
	while (i < data->map->height)
	{
		data->map->map[i] = \
			allocation(data, data->map->width + 1, sizeof(char));
		cpy_map(data, data->map->map[i], map[i]);
		i++;
	}
}

void	parse_map(t_data *data, char **map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (check_if_line_exist(map[i]))
		{
			if ((size_t)len < ft_strlen(map[i]))
				len = ft_strlen(map[i]);
		}
		else
		{
			check_if_other_line_exist(i, map);
			break ;
		}
		i++;
	}
	data->map->width = len;
	data->map->height = i;
	allocate_map(data, map);
	check_map_error(data);
}
