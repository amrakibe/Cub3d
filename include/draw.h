/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:19:56 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:40:45 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "cub3d.h"

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	angle;
	double	ply_x_pos;
	double	ply_y_pos;
}	t_coord;

typedef struct s_keys
{
	int	key_up;
	int	key_down;
	int	key_right;
	int	key_left;
	int	rot_lft;
	int	rot_rght;
	int	view_up;
	int	view_down;
}	t_keys;

typedef struct s_camera
{
	unsigned int	loun;
	double			ray_angle;
	double			x_horizontal;
	double			y_horizontal;
	double			x_vertical;
	double			y_vertical;
	double			dist_vert;
	double			dist_horz;
	int				chk_if_horz;
	int				chk_if_vert;
	double			ray_dist;
	double			dist_ply_proj;
	double			proj_wall;
	double			start_wall;
	double			end_wall;
	double			view_up_down;
	double			offset_x;
	double			angle_chk;
}	t_cam;

typedef struct image_utils
{
	unsigned int	*texture;
	void			*img;
	char			*addr;
	int				h;
	int				w;
	int				bpp;
	int				size_line;
	int				endian;
}	t_img;

#endif
