/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_texture_chk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:02:06 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:14:58 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_color(t_data *data, int i, char *line)
{
	if (i >= 4)
	{
		if (i == 4)
		{
			if (data->color->floor)
				error_file("Error\nF already exist");
			data->color->floor = add_color_elem(data, line);
		}
		else
		{
			if (data->color->ceiling)
				error_file("Error\nC already exist");
			data->color->ceiling = add_color_elem(data, line);
		}
	}
}

void	check_texture(t_data *data, int j, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (data->ply_stat->north)
			error_file("Error\nNO already exist");
		data->ply_stat->north = add_texture_elem(data, &line[j]);
	}
	if (!ft_strncmp(line, "SO", 2))
	{
		if (data->ply_stat->south)
			error_file("Error\nSO already exist");
		data->ply_stat->south = add_texture_elem(data, &line[j]);
	}
	if (!ft_strncmp(line, "EA", 2))
	{
		if (data->ply_stat->east)
			error_file("Error\nEA already exist");
		data->ply_stat->east = add_texture_elem(data, &line[j]);
	}
	if (!ft_strncmp(line, "WE", 2))
	{
		if (data->ply_stat->west)
			error_file("Error\nWE already exist");
		data->ply_stat->west = add_texture_elem(data, &line[j]);
	}
}

int	add_color_elem(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**sp;

	i = 0;
	sp = ft_split(line, ',');
	split_collect_addr(data, sp);
	check_clr_error(line);
	while (sp[i])
	{
		j = 0;
		while (sp[i][j])
		{
			if (!(sp[i][j] >= '0' && sp[i][j] <= '9'))
				error_file("Error:\n in color");
			j++;
		}
		if (check_clr_range(sp[i]))
			error_file("Error:\n invalid color");
		i++;
	}
	if (i != 3)
		error_file("Error:\n invalid RGB colors");
	return (color_converter(data, sp));
}

char	*add_texture_elem(t_data *data, char *file)
{
	int		fd;
	int		len;
	char	*texture;

	len = ft_strlen("./textures/");
	texture = 0;
	if (ft_strncmp(file, "./textures/", len))
		error_file("Error:\nInvalid texture");
	if (file[len] && (file[len] == ' ' || (file[len] >= 9 && file[len] <= 13)))
		error_file("Error:\nInvalid texture");
	else
	{
		len = ft_strlen(file);
		texture = allocation(data, len + 1, sizeof(char));
		ft_strlcpy(texture, file, len + 1);
		fd = open(texture, O_RDONLY);
		if (fd < 0)
			error_file("Error:\nInvalid texture file");
	}
	return (texture);
}
