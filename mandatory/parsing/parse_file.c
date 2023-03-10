/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:52:19 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 15:03:06 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i])
		error_file("Error:\nin the element");
	return (i);
}

static void	parse_the_line_helper(t_data *data, char **elem, char *line, int i)
{
	int	j;

	j = ft_strlen(elem[i]);
	if (!line[j])
		error_file("Error:\nin the element");
	if (line[j] != ' ' && !(line[j] >= 9 && line[j] <= 13))
		error_file("Error:\ndifferent element in the map");
	j += skip_space(&line[j]);
	check_color(data, i, &line[j]);
	check_texture(data, j, line);
}

static void	parse_the_line(t_data *data, char *line)
{
	int		i;
	char	**elem;

	i = 0;
	elem = ft_split(ELEM, ' ');
	split_collect_addr(data, elem);
	while (elem[i])
	{
		if (!ft_strncmp(elem[i], line, ft_strlen(elem[i])))
			break ;
		i++;
	}
	if (!elem[i])
		error_file("Error:\ndifferent element in the map");
	else
		parse_the_line_helper(data, elem, line, i);
}

void	parse_file(t_data *data)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (data->r_file[i])
	{
		line = ft_strtrim(data->r_file[i], "\t\v\r\f ");
		garbage_collector(data, line);
		if (len == 6 && line[0])
		{
			parse_map(data, &data->r_file[i]);
			return ;
		}
		else if (len < 6 && line[0])
		{
			len++;
			parse_the_line(data, line);
		}
		i++;
	}
	error_file("Error\nno existing for the map");
}
