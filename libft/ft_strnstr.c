/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:11:43 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/03 10:10:12 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	s = (char *) str;
	if (!ft_strlen(s) && !ft_strlen(to_find) && n == 0)
		return (s);
	if (!ft_strlen(to_find))
		return (s);
	while (i < n && s[i])
	{
		j = 0;
		while (s[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' && (i + j) < n)
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (0);
}
