/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:39:56 by amrakibe          #+#    #+#             */
/*   Updated: 2023/02/26 16:54:47 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	get_horizontal_intersect(t_data *data, double angle)
{
	if (data->ray->angle_chk != (double)0 && \
			data->ray->angle_chk != (double)180)
	{
		get_first_horizontal_intersect(data, angle);
		if (did_it_hit_the_wall(data, data->ray->x_horizontal, \
					data->ray->y_horizontal + 1, 0) && \
				did_it_hit_the_wall(data, data->ray->x_horizontal, \
					data->ray->y_horizontal - 1, 0))
		{
			while (1)
			{
				get_next_horizontal_intersect(data, angle);
				if (!did_it_hit_the_wall(data, data->ray->x_horizontal, \
							data->ray->y_horizontal + 1, 0) || \
						!did_it_hit_the_wall(data, data->ray->x_horizontal, \
							data->ray->y_horizontal - 1, 0))
					break ;
			}
		}
	}
	else
		data->ray->chk_if_vert = 1;
}

static void	get_vertical_intersect(t_data *data, double angle)
{
	if (data->ray->angle_chk != (double)270 && \
			data->ray->angle_chk != (double)90)
	{
		get_first_vertical_intersect(data, angle);
		if (did_it_hit_the_wall(data, data->ray->x_vertical + 1, \
					data->ray->y_vertical, 1) && \
				did_it_hit_the_wall(data, data->ray->x_vertical - 1, \
					data->ray->y_vertical, 1))
		{
			while (1)
			{
				get_next_vertical_intersect(data, angle);
				if (!did_it_hit_the_wall(data, data->ray->x_vertical + 1, \
							data->ray->y_vertical, 1) || \
						!did_it_hit_the_wall(data, data->ray->x_vertical - 1, \
							data->ray->y_vertical, 1))
					break ;
			}
		}
	}
	else
		data->ray->chk_if_horz = 1;
}

void	draw_rays(t_data *data)
{
	int		i;
	double	angle;
	double	angle_increment;

	i = 0;
	angle = data->ray->ray_angle;
	angle_increment = deg_to_rad(FOV) / WIN_W;
	data->draw_utils->x = 0;
	while (i <= WIN_W)
	{
		data->ray->chk_if_horz = 0;
		data->ray->chk_if_vert = 0;
		data->ray->angle_chk = floor(rad_to_deg(angle));
		get_horizontal_intersect(data, angle);
		get_vertical_intersect(data, angle);
		compare_the_intersects(data, angle);
		look_im_3d_now(data);
		if (data->ray->angle_chk == (double)360)
			angle = 0;
		angle += angle_increment;
		i++;
	}
}
