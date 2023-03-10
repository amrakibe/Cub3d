/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:13:36 by hkaddour          #+#    #+#             */
/*   Updated: 2022/10/25 17:07:30 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	i;
	int		st_n;
	char	*str;
	char	*ptr;

	i = 0;
	st_n = start;
	str = (char *) s;
	if (!s)
		return (0);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	while (str[start++] && i < n)
		i++;
	ptr = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (str[st_n] && i < n)
		ptr[i++] = str[st_n++];
	return (ptr);
}
