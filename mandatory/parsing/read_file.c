/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:20:56 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:29:59 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_file_exetention(char *file)
{
	if (ft_strcmp(&file[ft_strlen(file) - 4], ".cub"))
		error_file("Error in map exetention only take .cub maps");
}

static void	open_file(t_data *data)
{
	check_file_exetention(data->n_file);
	data->fd_map = open(data->n_file, O_RDONLY);
	if (!data->fd_map)
		error_file("Error in file");
}

static void	fill_read_file(t_data *data, int len)
{
	int	i;

	i = 0;
	data->fd_map = open(data->n_file, O_RDONLY);
	if (!data->fd_map)
		error_file("Error in file");
	while (i < len)
	{
		data->r_file[i] = grab_line(data, data->fd_map);
		i++;
	}
	close(data->fd_map);
}

void	read_file(t_data *data)
{
	int		len;
	char	*line;

	open_file(data);
	line = grab_line(data, data->fd_map);
	if (!line)
		error_file("Empty file");
	len = 1;
	while (line)
	{
		line = grab_line(data, data->fd_map);
		len++;
	}
	close(data->fd_map);
	data->r_file = ft_calloc(len + 1, sizeof(char *));
	garbage_collector(data, data->r_file);
	fill_read_file(data, len);
}
