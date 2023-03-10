/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:01:54 by amrakibe          #+#    #+#             */
/*   Updated: 2023/02/26 17:01:57 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	take_vertical_only(t_data *data, double angle)
{
	double	x;
	double	y;

	x = fabs(data->draw_utils->ply_x_pos - data->ray->x_vertical);
	y = fabs(data->draw_utils->ply_y_pos - data->ray->y_vertical);
	data->ray->dist_vert = sqrt((x * x) + (y * y));
	data->ray->ray_dist = \
		data->ray->dist_vert * cos(angle - data->draw_utils->angle);
	data->ray->offset_x = (int)data->ray->y_vertical % SQR_SIZE;
}

static void	take_horizontal_only(t_data *data, double angle)
{
	double	x;
	double	y;

	x = fabs(data->draw_utils->ply_x_pos - data->ray->x_horizontal);
	y = fabs(data->draw_utils->ply_y_pos - data->ray->y_horizontal);
	data->ray->dist_horz = sqrt((x * x) + (y * y));
	data->ray->ray_dist = \
		data->ray->dist_horz * cos(angle - data->draw_utils->angle);
	data->ray->offset_x = (int)data->ray->x_horizontal % SQR_SIZE;
}

static void	compare_them_both(t_data *data, double angle)
{
	double	x;
	double	y;

	x = fabs(data->draw_utils->ply_x_pos - data->ray->x_horizontal);
	y = fabs(data->draw_utils->ply_y_pos - data->ray->y_horizontal);
	data->ray->dist_horz = sqrt((x * x) + (y * y));
	x = fabs(data->draw_utils->ply_x_pos - data->ray->x_vertical);
	y = fabs(data->draw_utils->ply_y_pos - data->ray->y_vertical);
	data->ray->dist_vert = sqrt((x * x) + (y * y));
	if (data->ray->dist_horz < data->ray->dist_vert)
	{
		data->ray->ray_dist = \
			data->ray->dist_horz * cos(angle - data->draw_utils->angle);
		data->ray->offset_x = (int)data->ray->x_horizontal % SQR_SIZE;
		data->ray->chk_if_horz = 1;
	}
	else
	{
		data->ray->ray_dist = \
			data->ray->dist_vert * cos(angle - data->draw_utils->angle);
		data->ray->offset_x = (int)data->ray->y_vertical % SQR_SIZE;
		data->ray->chk_if_vert = 1;
	}
}

void	compare_the_intersects(t_data *data, double angle)
{
	if (data->ray->chk_if_vert)
		take_vertical_only(data, angle);
	else if (data->ray->chk_if_horz)
		take_horizontal_only(data, angle);
	else
		compare_them_both(data, angle);
}
