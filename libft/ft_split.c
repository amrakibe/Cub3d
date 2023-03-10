/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:29:46 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 11:57:37 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strcount(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != 0)
	{
		if (*s != c && *s)
		{
			len++;
			while (*s != 0 && *s != c)
				s++;
			continue ;
		}
		s++;
	}
	return (len);
}

static char	*ft_alloc_word_by_word(char *s, char c)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	ptr = ft_calloc(len + 1, sizeof(char));
	while (*s != c && *s)
		*ptr++ = *s++;
	*ptr = 0;
	return (ptr - len);
}

static void	ft_alloc_all(char *str, char c, int w, char **ptr)
{
	while (*str)
	{
		if (*str != c && *str)
		{
			ptr[w++] = ft_alloc_word_by_word(str, c);
			while (*str != c && *str)
				str++;
			continue ;
		}
		str++;
	}
	ptr[w] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**ptr;
	char	*str;

	if (!s)
		return (0);
	w = 0;
	str = (char *) s;
	ptr = ft_calloc((ft_strcount(str, c) + 1), sizeof(char *));
	ft_alloc_all(str, c, w, ptr);
	return (ptr);
}
