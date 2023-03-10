/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:34:18 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/08 18:58:15 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*src1;
	char			*dest1;

	i = 0;
	src1 = (char *) src;
	dest1 = dest;
	if (!dest && !src)
		return (NULL);
	while (n > i)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
