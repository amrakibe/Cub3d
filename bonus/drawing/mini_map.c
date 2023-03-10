/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:56:21 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 16:00:57 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	init_data_mini_map_draw(t_data *data)
{
	data->mini->y = (int)(floor(data->draw_utils->ply_y_pos) / SQR_SIZE) *10;
	data->mini->x = (int)(floor(data->draw_utils->ply_x_pos) / SQR_SIZE) *10;
	data->mini->ply_x = data->mini->x;
	data->mini->ply_y = data->mini->y;
	data->mini->start_x = data->mini->x - (340 / 2);
	if (data->mini->start_x < 0)
		data->mini->start_x = 0;
	data->mini->end_x = data->mini->start_x + 340;
	if (data->mini->end_x >= data->map->width * 10)
		data->mini->end_x = data->map->width * 10;
	data->mini->start_y = data->mini->y - (200 / 2);
	if (data->mini->start_y < 0)
		data->mini->start_y = 0;
	data->mini->end_y = data->mini->start_y + 200;
	if (data->mini->end_y >= data->map->height * 10)
		data->mini->end_y = data->map->height * 10;
	data->mini->y = data->mini->start_y;
}

static void	draw_player_mini_map(t_data *data)
{
	data->draw_utils->x = data->mini->hld_x + 5;
	data->draw_utils->y = data->mini->hld_y + 5;
	data->draw_utils->x_next = \
		data->draw_utils->x + cos(data->draw_utils->angle) * 20;
	data->draw_utils->y_next = \
		data->draw_utils->y + sin(data->draw_utils->angle) * 20;
	dda(data, 0xff0000);
	data->mini->x = data->mini->hld_x;
	while (data->mini->x < data->mini->hld_x + 10)
	{
		data->mini->y = data->mini->hld_y;
		while (data->mini->y < data->mini->hld_y + 10)
			mlx_put_pixel_to_img(\
				data, data->mini->x, data->mini->y++, 0x698269);
		data->mini->x++;
	}
}

static void	mini_map_draw_helper(t_data *data, int *x, int *y)
{
	if (data->map->map[data->mini->y / 10][data->mini->x / 10] == '1')
		mlx_put_pixel_to_img(data, (*x), (*y), 0xAA5656);
	if (data->map->map[data->mini->y / 10][data->mini->x / 10] == '0' \
		|| data->map->map[data->mini->y / 10][data->mini->x / 10] == \
		data->map->player)
		mlx_put_pixel_to_img(data, (*x), (*y), 0xFFFBEB);
	if (data->mini->x == data->mini->ply_x \
			&& data->mini->y == data->mini->ply_y)
	{
		data->mini->hld_x = (*x);
		data->mini->hld_y = (*y);
	}
	data->mini->x++;
	(*x)++;
}

void	mini_map_draw(t_data *data)
{
	int	x;
	int	y;

	init_data_mini_map_draw(data);
	y = 0;
	while (data->mini->y < data->mini->end_y)
	{
		data->mini->x = data->mini->start_x;
		x = 0;
		while (data->mini->x < data->mini->end_x)
			mini_map_draw_helper(data, &x, &y);
		data->mini->y++;
		y++;
	}
	draw_player_mini_map(data);
}
