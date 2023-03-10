/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:46:53 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:29:37 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	convert_hex_to_dec(char *str)
{
	int	len;
	int	base;
	int	rslt;

	len = ft_strlen(str) - 1;
	base = 1;
	rslt = 0;
	while (str[len] && len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
			rslt += (str[len] - 48) * base;
		else if (str[len] >= 'A' && str[len] <= 'F')
			rslt += (str[len] - 55) * base;
		else if (str[len] >= 'a' && str[len] <= 'f')
			rslt += (str[len] - 87) * base;
		base *= 16;
		len--;
	}
	return (rslt);
}

static char	*convert_to_hex(t_data *data, int clr)
{
	int		i;
	int		hld;
	char	*rslt;

	i = 0;
	rslt = allocation(data, 3, sizeof(char));
	hld = clr / 16;
	if (hld >= 0 && hld <= 9)
		rslt[0] = hld + 48;
	else
		rslt[0] = hld + 55;
	hld = clr % 16;
	if (hld >= 0 && hld <= 9)
		rslt[1] = hld + 48;
	else
		rslt[1] = hld + 55;
	return (rslt);
}

int	color_converter(t_data *data, char **rgb)
{
	int		i;
	char	*hld;
	char	*hex;

	i = 0;
	hex = allocation(data, 7, sizeof(char));
	while (*rgb)
	{
		hld = convert_to_hex(data, ft_atoi(*rgb));
		ft_strlcpy(&hex[i], hld, 3);
		i += 2;
		rgb++;
	}
	return (convert_hex_to_dec(hex));
}
