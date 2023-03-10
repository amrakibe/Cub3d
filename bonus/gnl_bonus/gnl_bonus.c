/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:37 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:26:51 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_bonus.h"

static void	read_line(t_gnl *t_line, int fd)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, t_line->buff, 1);
		if (i <= 0)
			return ;
		if (t_line->buff[0] == '\n')
		{
			if (!t_line->line)
				t_line->line = add_dup(t_line->data, "");
			return ;
		}
		t_line->tmp = t_line->line;
		if (!t_line->tmp)
			t_line->tmp = allocation(t_line->data, 1, sizeof(char));
		t_line->line = ft_strjoin(t_line->tmp, t_line->buff);
		garbage_collector(t_line->data, t_line->line);
	}
}

char	*grab_line(t_data *data, int fd)
{
	t_gnl		t_line;

	if (fd < 0)
		return (0);
	t_line.line = 0;
	t_line.buff = allocation(data, 2, sizeof(char));
	t_line.data = data;
	read_line(&t_line, fd);
	if (!t_line.line)
		return (0);
	return (t_line.line);
}
