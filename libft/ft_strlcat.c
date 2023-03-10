/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:16:08 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/03 12:18:32 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size_dst)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	j = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size_dst < dst_len + 1)
		return (src_len + size_dst);
	if (size_dst > dst_len + 1)
	{
		while (*(src + i) && j < size_dst - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		*(dst + j) = '\0';
	}
	return (dst_len + src_len);
}
