/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:08:06 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 14:52:23 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	get_textures_helper(t_data *data)
{
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->south, &data->texture[3].w, &data->texture[3].h);
	if (!data->texture[3].img)
		error_file("Error\nin img");
	data->texture[3].texture = (unsigned int *)mlx_get_data_addr(\
			data->texture[3].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
}

void	get_textures(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->east, &data->texture[0].w, &data->texture[0].h);
	if (!data->texture[0].img)
		error_file("Error\nin img");
	data->texture[0].texture = (unsigned int *)mlx_get_data_addr(\
			data->texture[0].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->north, &data->texture[1].w, &data->texture[1].h);
	if (!data->texture[1].img)
		error_file("Error\nin img");
	data->texture[1].texture = (unsigned int *)mlx_get_data_addr(\
			data->texture[1].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->west, &data->texture[2].w, &data->texture[2].h);
	if (!data->texture[2].img)
		error_file("Error\nin img");
	data->texture[2].texture = (unsigned int *)mlx_get_data_addr(\
			data->texture[2].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
	get_textures_helper(data);
}

unsigned int	texture_clr(t_data *data, double y, int i)
{
	int				offset_x;
	int				offset_y;

	offset_y = y + (data->ray->proj_wall / 2) - data->ray->view_up_down;
	offset_x = (data->ray->offset_x / SQR_SIZE) * data->texture[i].w;
	offset_y = \
		((offset_y) * ((double)data->texture[i].h / data->ray->proj_wall));
	return ((unsigned int)data->texture[i].texture \
			[(int)((offset_y * data->texture[i].h) + offset_x)]);
}
