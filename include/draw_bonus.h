/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:28:25 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 17:04:25 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H
# include "cub3d_bonus.h"

typedef struct s_mini_map
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	ply_x;
	int	ply_y;
	int	hld_x;
	int	hld_y;
}	t_mini_map;

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	x_next;
	double	y_next;
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
	int	sprite;
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
