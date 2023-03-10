/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:14:09 by hkaddour          #+#    #+#             */
/*   Updated: 2021/12/08 18:21:06 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *) s;
	ptr = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
