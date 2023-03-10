/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 16:34:01 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	color_piker(t_data *data)
{
	if (data->ray->chk_if_horz && is_view_down(data))
		data->ray->loun = texture_clr(data, data->draw_utils->y, 0);
	else if (data->ray->chk_if_horz && is_view_up(data))
		data->ray->loun = texture_clr(data, data->draw_utils->y, 1);
	if (data->ray->chk_if_vert && is_view_right(data))
		data->ray->loun = texture_clr(data, data->draw_utils->y, 2);
	else if (data->ray->chk_if_vert && is_view_left(data))
		data->ray->loun = texture_clr(data, data->draw_utils->y, 3);
}

void	look_im_3d_now(t_data *data)
{
	data->ray->dist_ply_proj = (WIN_W / 2) / tan(deg_to_rad(FOV / 3) * 2);
	data->ray->proj_wall = \
		fabs((SQR_SIZE / data->ray->ray_dist) * data->ray->dist_ply_proj);
	data->ray->start_wall = \
		data->ray->view_up_down - (data->ray->proj_wall / 2);
	data->ray->end_wall = data->ray->start_wall + (data->ray->proj_wall);
	data->draw_utils->y = 0;
	while (data->draw_utils->y <= WIN_H)
	{
		if (data->draw_utils->y < data->ray->start_wall)
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x), \
					fabs(data->draw_utils->y), data->color->ceiling);
		else if (data->draw_utils->y >= data->ray->start_wall \
				&& data->draw_utils->y <= data->ray->end_wall)
		{
			color_piker(data);
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x), \
					fabs(data->draw_utils->y), data->ray->loun);
		}
		else
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x), \
					fabs(data->draw_utils->y), data->color->floor);
		data->draw_utils->y++;
	}
	data->draw_utils->x++;
}
