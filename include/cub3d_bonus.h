/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:26:19 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 17:03:49 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# define ELEM "NO SO EA WE F C"
# define WIN_W 1366
# define WIN_H 768
# define SPEED 100.0
# define ROT_SPEED 5.0
# define FOV 60
# define SQR_SIZE 500
# define ROT_RIGHT 123
# define ROT_LEFT 124
# define RIGHT 2
# define LEFT 0
# define UP 13
# define DOWN 1
# define VIEW_UP 126
# define VIEW_DOWN 125
# define SPRITE 49
# define ESC 53
# include "../libft/libft.h"
# include "../bonus/gnl_bonus/gnl_bonus.h"
# include "draw_bonus.h"

typedef struct image_utils	t_img;
typedef struct s_mini_map	t_mini_map;
typedef struct s_coordinate	t_coord;
typedef struct s_keys		t_keys;
typedef struct s_camera		t_cam;

typedef struct player_stat
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_p_stat;

typedef struct s_color
{
	int	floor;
	int	ceiling;
}	t_color;

typedef struct s_free
{
	void			*value;
	struct s_free	*next;
}	t_free;

typedef struct s_map
{
	int		player_exist;
	char	player;
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_img	*utils;
}	t_mlx;

typedef struct s_data
{
	char		*n_file;
	int			fd_map;
	char		**r_file;
	int			sp_mot;
	t_mini_map	*mini;
	t_img		*texture;
	t_img		*sprite;
	t_p_stat	*ply_stat;
	t_color		*color;
	t_map		*map;
	t_mlx		*mlx;
	t_coord		*draw_utils;
	t_keys		*key_mv;
	t_cam		*ray;
	t_free		*g_collect;
}	t_data;

/******** Function of main **********/
void			init_data(t_data *data, char *file);
void			*allocation(t_data *data, int count, int size);
char			*add_dup(t_data *data, char *s);

/******** Function of error **********/
void			error_alloc(void);
void			error_file(char *msg);

/******** Function of free **********/
void			garbage_collector(t_data *data, void *addr);
void			free_all(t_data *data);
void			split_collect_addr(t_data *data, char **sp);

/******** Function of parsing **********/
void			read_file(t_data *data);
void			parse_file(t_data *data);
char			*add_texture_elem(t_data *data, char *file);
int				color_converter(t_data *data, char **rgb);
void			parse_map(t_data *data, char **map);
void			check_map_error(t_data *data);
void			check_color(t_data *data, int i, char *line);
void			check_texture(t_data *data, int j, char *line);
int				add_color_elem(t_data *data, char *line);
void			check_clr_error(char *line);
int				check_clr_range(char *nbr);

/******** Function of drawing **********/
void			mini_map_draw(t_data *data);
void			dda(t_data *data, int loun);
void			sprite_init(t_data *data);
void			window_init(t_data *data);
int				close_win(t_data *data);
int				did_it_hit_the_wall(t_data *data, double x, double y, int chk);
void			draw(t_data *data);
void			einstein_drawing(t_data *data);
void			catch_player_pos(t_data *data);
void			make_and_init_image(t_data *data);
void			mlx_put_pixel_to_img(t_data *data, int x, int y, int clr);
void			draw_rays(t_data *data);
void			look_im_3d_now(t_data *data);
void			get_textures(t_data *data);
void			compare_the_intersects(t_data *data, double angle);
void			get_first_horizontal_intersect(t_data *data, double angle);
void			get_next_horizontal_intersect(t_data *data, double angle);
void			get_first_vertical_intersect(t_data *data, double angle);
void			get_next_vertical_intersect(t_data *data, double angle);
unsigned int	texture_clr(t_data *data, double y, int i);

/******** Function of drawing sight **********/
int				is_view_up(t_data *data);
int				is_view_right(t_data *data);
int				is_view_down(t_data *data);
int				is_view_left(t_data *data);

/******** Function of Keys **********/
int				keys(t_data *data);
int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);
int				view_up_down_key(t_data *data);
void			rotation_key(t_data *data);
void			sprite_motion(t_data *data);

/******** Function of Math **********/
double			deg_to_rad(double degree);
double			rad_to_deg(double radians);

#endif
