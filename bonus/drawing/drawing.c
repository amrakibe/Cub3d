/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:39 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:32:25 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw(t_data *data)
{
	mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
	einstein_drawing(data);
}

int	did_it_hit_the_wall(t_data *data, double x, double y, int chk)
{
	int	x_index;
	int	y_index;

	x_index = (int)floor(x / SQR_SIZE);
	y_index = (int)floor(y / SQR_SIZE);
	if ((x_index >= 0 && x_index < data->map->width) && \
			(y_index >= 0 && y_index < data->map->height))
	{
		if (data->map->map[y_index][x_index] != '1')
			return (1);
	}
	else
	{
		if (chk)
			data->ray->chk_if_horz = 1;
		else
			data->ray->chk_if_vert = 1;
	}
	return (0);
}

void	catch_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == data->map->player)
			{
				data->draw_utils->ply_x_pos = j * SQR_SIZE + (SQR_SIZE / 2);
				data->draw_utils->ply_y_pos = i * SQR_SIZE + (SQR_SIZE / 2);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	einstein_drawing(t_data *data)
{
	make_and_init_image(data);
	draw_rays(data);
	mini_map_draw(data);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, \
			data->mlx->utils->img, 0, 0);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, \
			data->sprite[data->sp_mot].img, (WIN_W / 2) - \
			(data->sprite[data->sp_mot].w / 2), \
			WIN_H - data->sprite[data->sp_mot].h);
}
