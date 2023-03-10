/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:42:18 by amrakibe          #+#    #+#             */
/*   Updated: 2023/02/26 16:42:20 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_first_horizontal_intersect(t_data *data, double angle)
{
	if (is_view_up(data))
		data->ray->y_horizontal = \
			floor(data->draw_utils->ply_y_pos / SQR_SIZE) * SQR_SIZE;
	else
		data->ray->y_horizontal = \
			floor(data->draw_utils->ply_y_pos / SQR_SIZE) * SQR_SIZE + SQR_SIZE;
	data->ray->x_horizontal = data->draw_utils->ply_x_pos + \
		(data->ray->y_horizontal - data->draw_utils->ply_y_pos) / tan(angle);
}

void	get_next_horizontal_intersect(t_data *data, double angle)
{
	if (is_view_up(data))
	{
		data->ray->y_horizontal -= SQR_SIZE;
		data->ray->x_horizontal += (-SQR_SIZE / tan(angle));
	}
	else
	{
		data->ray->y_horizontal += SQR_SIZE;
		data->ray->x_horizontal += (SQR_SIZE / tan(angle));
	}
}

void	get_first_vertical_intersect(t_data *data, double angle)
{
	if (is_view_right(data))
		data->ray->x_vertical = \
			floor(data->draw_utils->ply_x_pos / SQR_SIZE) * SQR_SIZE + SQR_SIZE;
	else
		data->ray->x_vertical = \
			floor(data->draw_utils->ply_x_pos / SQR_SIZE) * SQR_SIZE;
	data->ray->y_vertical = data->draw_utils->ply_y_pos + \
		(data->ray->x_vertical - data->draw_utils->ply_x_pos) * tan(angle);
}

void	get_next_vertical_intersect(t_data *data, double angle)
{
	if (is_view_right(data))
	{
		data->ray->x_vertical += SQR_SIZE;
		data->ray->y_vertical += (SQR_SIZE * tan(angle));
	}
	else
	{
		data->ray->x_vertical -= SQR_SIZE;
		data->ray->y_vertical += (-SQR_SIZE * tan(angle));
	}
}
