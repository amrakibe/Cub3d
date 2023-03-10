/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:57:45 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/04 21:04:11 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *) s;
	while (i >= 0)
	{
		if (str[i] == (char) c)
			break ;
		i--;
	}
	if (str[i] != (char) c)
		return (NULL);
	return (&str[i]);
}
