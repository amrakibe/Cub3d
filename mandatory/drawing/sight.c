/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:41:18 by amrakibe          #+#    #+#             */
/*   Updated: 2023/02/26 16:41:20 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_view_up(t_data *data)
{
	if (data->ray->angle_chk >= (double)180 && \
			data->ray->angle_chk <= (double)360)
		return (1);
	return (0);
}

int	is_view_right(t_data *data)
{
	if ((data->ray->angle_chk >= (double)270 && \
			data->ray->angle_chk <= (double)360) || \
			(data->ray->angle_chk >= (double)0 && \
			data->ray->angle_chk <= (double)90))
		return (1);
	return (0);
}

int	is_view_down(t_data *data)
{
	if (!is_view_up(data))
		return (1);
	return (0);
}

int	is_view_left(t_data *data)
{
	if (!is_view_right(data))
		return (1);
	return (0);
}
