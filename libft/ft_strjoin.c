/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:11:37 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 11:58:32 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = ft_calloc(len + 1, sizeof(char));
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	return ((char *) ptr - len);
}
