/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:15:03 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 13:02:29 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../include/cub3d.h"
# include "../../libft/libft.h"

typedef struct s_data	t_data;

typedef struct grab_line
{
	char		*buff;
	char		*tmp;
	char		*line;
	t_data		*data;
}	t_gnl;

char	*grab_line(t_data *data, int fd);

#endif
