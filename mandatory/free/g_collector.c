/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:46:17 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 14:00:28 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	split_collect_addr(t_data *data, char **sp)
{
	garbage_collector(data, sp);
	while (*sp)
		garbage_collector(data, *sp++);
}

void	free_all(t_data *data)
{
	t_free	*node;

	node = data->g_collect;
	while (node)
	{
		if (node->value)
			free(node->value);
		free(node);
		node = node->next;
	}
}

void	garbage_collector(t_data *data, void *addr)
{
	t_free	*node;

	node = data->g_collect;
	if (!node)
		return ;
	while (node->next)
		node = node->next;
	node->next = ft_calloc(1, sizeof(t_free));
	node->next->value = addr;
}
