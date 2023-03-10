/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 16:35:10 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(t_data *data)
{
	printf("Window closed!\n");
	free_all(data);
	exit(0);
}

void	init_drawing_data(t_data *data)
{
	if (data->map->player == 'E')
		data->draw_utils->angle = 0;
	else if (data->map->player == 'N')
		data->draw_utils->angle = M_PI / 2;
	else if (data->map->player == 'W')
		data->draw_utils->angle = M_PI;
	else if (data->map->player == 'S')
		data->draw_utils->angle = 3 * M_PI / 2;
	if ((int)round(rad_to_deg(data->draw_utils->angle)) == 0)
		data->ray->ray_angle = deg_to_rad(360 - (FOV / 2));
	else if ((int)round(rad_to_deg(data->draw_utils->angle)) < 30)
		data->ray->ray_angle = deg_to_rad(360 - \
			(fabs(rad_to_deg(data->draw_utils->angle) - (FOV / 2))));
	else
		data->ray->ray_angle = \
			data->draw_utils->angle - deg_to_rad(FOV / 2);
	data->ray->view_up_down = (WIN_H / 2);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	init_drawing_data(data);
	catch_player_pos(data);
	get_textures(data);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L << 0, close_win, data);
	mlx_hook(data->mlx->win, 2, 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 0, key_release, data);
	mlx_loop_hook(data->mlx->init, keys, data);
	mlx_loop(data->mlx->init);
}
