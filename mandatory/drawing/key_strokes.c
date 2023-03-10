/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:38:22 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:30:33 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_walls_right_left(t_data *data, int chk)
{
	double	x;
	double	y;

	if (!chk)
	{
		x = data->draw_utils->ply_x_pos - sin(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos + cos(data->draw_utils->angle) * SPEED;
	}
	else
	{
		x = data->draw_utils->ply_x_pos + sin(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos - cos(data->draw_utils->angle) * SPEED;
	}
	return (did_it_hit_the_wall(data, x, y, 0) && \
		did_it_hit_the_wall(data, data->draw_utils->ply_x_pos, y, 0) && \
		did_it_hit_the_wall(data, x, data->draw_utils->ply_y_pos, 0));
}

int	check_walls_up_down(t_data *data, int chk)
{
	double	x;
	double	y;

	if (!chk)
	{
		x = data->draw_utils->ply_x_pos + cos(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos + sin(data->draw_utils->angle) * SPEED;
	}
	else
	{
		x = data->draw_utils->ply_x_pos - cos(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos - sin(data->draw_utils->angle) * SPEED;
	}
	return (did_it_hit_the_wall(data, x, y, 0) && \
		did_it_hit_the_wall(data, data->draw_utils->ply_x_pos, y, 0) && \
		did_it_hit_the_wall(data, x, data->draw_utils->ply_y_pos, 0));
}

static int	left_right_key(t_data *data)
{
	if (data->key_mv->key_right)
	{
		if (check_walls_right_left(data, 0))
		{
			data->draw_utils->ply_x_pos -= sin(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos += cos(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	if (data->key_mv->key_left)
	{
		if (check_walls_right_left(data, 1))
		{
			data->draw_utils->ply_x_pos += sin(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos -= cos(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	return (0);
}

static int	up_down_key(t_data *data)
{
	if (data->key_mv->key_up)
	{
		if (check_walls_up_down(data, 0))
		{
			data->draw_utils->ply_x_pos += cos(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos += sin(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	if (data->key_mv->key_down)
	{
		if (check_walls_up_down(data, 1))
		{
			data->draw_utils->ply_x_pos -= cos(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos -= sin(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	return (0);
}

int	keys(t_data *data)
{
	if (data->key_mv->key_left || data->key_mv->key_right)
	{
		if (left_right_key(data))
			draw(data);
	}
	if (data->key_mv->key_up || data->key_mv->key_down)
	{
		if (up_down_key(data))
			draw(data);
	}
	if (data->key_mv->view_up || data->key_mv->view_down)
	{
		if (view_up_down_key(data))
			draw(data);
	}
	if (data->key_mv->rot_rght || data->key_mv->rot_lft)
	{
		rotation_key(data);
		draw(data);
	}
	return (0);
}
