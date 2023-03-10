/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 15:11:57 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	*allocation(t_data *data, int count, int size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	garbage_collector(data, ptr);
	return (ptr);
}

char	*add_dup(t_data *data, char *s)
{
	char	*ptr;

	ptr = ft_strdup(s);
	garbage_collector(data, ptr);
	return (ptr);
}

void	init_data(t_data *data, char *file)
{
	data->n_file = file;
	data->g_collect = ft_calloc(1, sizeof(t_free));
	data->mini = allocation(data, 1, sizeof(t_mini_map));
	data->texture = allocation(data, 4, sizeof(t_img));
	data->sprite = allocation(data, 4, sizeof(t_img));
	data->ply_stat = allocation(data, 1, sizeof(t_p_stat));
	data->color = allocation(data, 1, sizeof(t_color));
	data->map = allocation(data, 1, sizeof(t_map));
	data->mlx = allocation(data, 1, sizeof(t_mlx));
	data->draw_utils = allocation(data, 1, sizeof(t_coord));
	data->key_mv = allocation(data, 1, sizeof(t_keys));
	data->ray = allocation(data, 1, sizeof(t_cam));
	data->mlx->utils = allocation(data, 1, sizeof(t_img));
}
