/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:46:40 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/08 18:03:36 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;

	i = 0;
	str1 = (unsigned char *) str;
	while (n > i)
	{
		str1[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
