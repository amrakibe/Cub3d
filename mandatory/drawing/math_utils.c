/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:42:55 by amrakibe          #+#    #+#             */
/*   Updated: 2023/02/26 16:43:03 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	deg_to_rad(double degree)
{
	return (degree * (M_PI / 180.0));
}
