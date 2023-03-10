/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:52:10 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/08 18:18:52 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < (int)ft_strlen(s))
	{
		if (str[i] == (char) c)
			break ;
		i++;
	}
	if (str[i] != (char) c)
		return (NULL);
	return (&str[i]);
}
