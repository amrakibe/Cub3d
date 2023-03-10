/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:50:12 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/08 18:02:11 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) str;
	while (i < n)
	{
		if (s[i] == (unsigned char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
