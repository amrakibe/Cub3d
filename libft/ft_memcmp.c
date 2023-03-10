/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:15:08 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/03 17:48:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str3;

	i = 0;
	str = (unsigned char *) str1;
	str3 = (unsigned char *) str2;
	while (n > i)
	{
		if (str[i] == str3[i])
			i++;
		else if (str[i] != str3[i])
			return (str[i] - str3[i]);
	}
	return (0);
}
