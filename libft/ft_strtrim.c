/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:51:09 by hkaddour          #+#    #+#             */
/*   Updated: 2022/10/16 11:38:50 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(char str, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;
	char	*str;
	char	*sep;

	if (!s1 || !set)
		return (0);
	str = (char *) s1;
	sep = (char *) set;
	i = 0;
	j = ft_strlen(str);
	while (str[i] && ft_check(str[i], sep))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (ft_check(str[j - 1], sep))
		j--;
	ptr = ft_calloc((j - i) + 1, sizeof(char));
	ft_strlcpy(ptr, &str[i], j - i + 1);
	return (ptr);
}
