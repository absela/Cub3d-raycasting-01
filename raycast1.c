/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:26:30 by absela            #+#    #+#             */
/*   Updated: 2023/03/20 15:16:52 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_ray_angle(double ray_ang, int flag)
{
    if (flag == 1)
    {
        if (ray_ang == 0)
            return (0);
        if (ray_ang > 180)
            return (1);
        else
            return (-1);
    }
    else
    {
        if (ray_ang == 90 || ray_ang == 270)
            return (0);
        if (ray_ang > 270 || ray_ang < 90)
            return (1);
        else
            return (-1);
    }
}

double x_intersection(t_mlx *mlx, double ray_ang, t_test    *pos)
{
    int check;
    double xa;
    double ya;
    // double y_intersection;
    // double x_intersection;
    double distance;

    check = get_ray_angle(ray_ang, 1);
    if (!check)
        return (HUGE_VALF);
    distance = 0;
    ya = TILE * check;
    xa = ya / -tan(to_radian(ray_ang));
    if (check != -1)
        pos->y_inter = (floor(mlx->ply->player_pos_y / TILE) * TILE) + TILE;
    else
        pos->y_inter = (floor(mlx->ply->player_pos_y / TILE) * TILE);
    pos->x_inter = mlx->ply->player_pos_x + (mlx->ply->player_pos_y - pos->y_inter) / tan(to_radian(ray_ang));
    if(pos->x_inter < 0 || pos->x_inter > mlx->map->map_width * TILE || pos->y_inter < 0 || pos->y_inter > mlx->map->map_height * TILE)
        return (HUGE_VALF);
    if(check == -1)
        pos->y_inter -= 1;
    while ((pos->x_inter / TILE) > - 1 &&  (pos->x_inter / TILE) < mlx->map->map_width && mlx->map->map[(int)(pos->y_inter / TILE)][(int)(pos->x_inter / TILE)] != '1')
    {
        pos->x_inter += xa;
        pos->y_inter += ya;
    }
    distance = sqrt(pow((mlx->ply->player_pos_x - pos->x_inter), 2) + pow((mlx->ply->player_pos_y - pos->y_inter), 2));
    // dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,pos->x_inter ,pos->y_inter, 0, 0, 0x00FF00);
    return (distance);
}

double y_intersection(t_mlx *mlx, double ray_ang, t_test    *pos)
{
    int check;
    double xa;
    double ya;
    double distance;

    check = get_ray_angle(ray_ang, 2);
    if (!check)
        return (HUGE_VALF);
    xa = TILE * check;
    ya = xa * -tan(to_radian(ray_ang));
    if (check != -1)
        pos->x_inter = (floor(mlx->ply->player_pos_x / TILE) * TILE) + TILE;
    else
        pos->x_inter = (floor(mlx->ply->player_pos_x / TILE) * TILE);
    pos->y_inter = mlx->ply->player_pos_y + (mlx->ply->player_pos_x - pos->x_inter) *  tan(to_radian(ray_ang));
    distance = 0;
    if(pos->x_inter < 0 || pos->x_inter > mlx->map->map_width * TILE || pos->y_inter < 0 || pos->y_inter > mlx->map->map_height * TILE)
        return (INFINITY);
    if(check == -1)
        pos->x_inter -= 1;
    while ((pos->y_inter / TILE) > - 1 &&  (pos->y_inter / TILE) < mlx->map->map_height && mlx->map->map[(int)(pos->y_inter / TILE)][(int)(pos->x_inter / TILE)] != '1')
    {
        pos->x_inter += xa;
        pos->y_inter += ya;
    }
    distance = sqrt(pow((mlx->ply->player_pos_x - pos->x_inter), 2) + pow((mlx->ply->player_pos_y - pos->y_inter), 2));
    // dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,pos->x_inter ,pos->y_inter, 0, 0, 0xFF0000);
    return (distance);
}

double	normalize_ray(double rl, double ra, t_mlx *data)
{
	double	res;
	double	rpa;

	if (ra < data->ply->ply_angle)
		rpa = data->ply->ply_angle - ra;
	else
		rpa = ra - data->ply->ply_angle;
	res = rl * cos(to_radian(rpa));
	return (res);
}

double  cast_ray(t_mlx *mlx, double ray_angl)
{
    double x_distance ;
    double y_distance ;
    t_test posx;
    t_test posy;

    x_distance = x_intersection(mlx, ray_angl, &posx);
    y_distance = y_intersection(mlx, ray_angl, &posy);
    if (y_distance >= x_distance)
    {
        // dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,posx.x ,posx.y, 0, 0, 0xFFFFFF);
        return(normalize_ray(x_distance, ray_angl, mlx));
    }
    else
    {
        // dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,posy.x ,posy.y, 0, 0, 0xFF0000);
        return(normalize_ray(y_distance, ray_angl, mlx));
    }
    return (0);
}

void cast_all_rays(t_mlx *mlx)
{
    int i;
    int x;
    double ray_angl;

    x = mlx->win_width;
    i = x - 1;
    mlx->rays = malloc(sizeof(t_ray) * x);
    while (i >= 0)
    {
        ray_angl = mlx->ply->ply_angle + (mlx->ply->field_of_view / 2) - (mlx->angle_btw_rays * (double)i);
        ray_angl = angl_limit(ray_angl);
        mlx->rays[i].ray_angle = ray_angl;
        mlx->rays[i].distance = cast_ray(mlx, ray_angl);
        i--;
    }

}