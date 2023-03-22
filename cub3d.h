/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:47:02 by absela            #+#    #+#             */
/*   Updated: 2023/03/22 02:06:24 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define TILE 32
# define MVSPEED 4
# define TUSPEED 3
# define W_WITH 900
# define W_HEIGHT 600


typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map{
	char	**map;
	int		map_width;
	int		map_height;
}				t_map;

typedef struct s_ply{
	double	player_pos_x;
	double	player_pos_y;
	double	field_of_view;
	double	ply_angle;
	int		walk_direction;
	int		turn_direction;
}				t_ply;

typedef struct s_ray{
	double	ray_angle;
	double	distance;
	int		wall_posx;
	int		wall_posy;
	int		is_h;
}				t_ray;

typedef struct s_test{
	double		x_inter;
	double		y_inter;
}				t_test;

typedef struct s_mlx{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	double	angle_btw_rays;
	double	pro_plane;
	t_data	*img;
	t_map	*map;
	t_ply	*ply;
	t_ray	*rays;
}				t_mlx;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**r_map(char *str);
void	init_all(t_mlx *mlx, char **av);
int		on_keydown(int keycode, t_mlx *mlx);
int		on_keyup(int keycode, t_mlx *mlx);
void	move_ply(t_mlx *mlx);
void	draw_world_2d(t_mlx *mlx);
void	rotate_player(t_mlx	*mlx);
void	cast_all_rays(t_mlx *mlx);
double	angl_limit(double ra);
double	to_radian(double n);
void	sky(t_mlx *mlx);
void	floorxx(t_mlx *mlx);
void	sky_and_floor(t_mlx *mlx);
void	rend_3D(t_mlx *mlx);
void	render_slice(t_mlx *mlx, int slice, int x);
void	render_walls3d(t_mlx *mlx);
int		on_mousemove(int x, int y, t_mlx *mlx);
void	dda(t_mlx *data, double X0, double Y0, double X1, double Y1, double angle, double scale,int color);

#endif