#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"


#define TILE 32
#define MVSPEED 3
#define TUSPEED 5


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map{
    char **map;
    int map_width;
    int map_height;
}           t_map;

typedef struct s_ply{
    double player_pos_x;
    double player_pos_y;
    int     field_of_view;
    double  ply_angle;
    int walk_direction;
    int turn_direction;

}               t_ply;

typedef struct s_ray{
    double ray_angle;
    double distance;
    int    wall_posx;
    int    wall_posy;
    int     is_h;
}              t_ray;

typedef struct s_mlx{
    void    *mlx;
    void    *mlx_win;
    int     win_width;
    int     win_height;
    double  angle_btw_rays;
    double  pro_plane;
    t_data  *img;
    t_map   *map;
    t_ply   *ply;
    t_ray   *rays;
}           t_mlx;






void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**r_map(char	*str);
void    init_all(t_mlx **mlx, char **av);
int     on_keydown(int keycode, t_mlx *mlx);
int     on_keyup(int keycode, t_mlx *mlx);
void    move_ply(t_mlx *mlx);
void    draw_world_2d(t_mlx *mlx);
void	rotate_player(t_mlx	*mlx);
void    dda(t_mlx *data, double X0, double Y0, double X1, double Y1, double angle, double scale,int color);
void    cast_all_rays(t_mlx *mlx);
double  angl_limit(double ra);
void    test_rays(t_mlx *mlx);
double to_radian(double n);

#endif