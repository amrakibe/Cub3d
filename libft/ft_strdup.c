/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:09:21 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/30 15:04:09 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
