/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:26:30 by absela            #+#    #+#             */
/*   Updated: 2023/03/26 20:03:01 by absela           ###   ########.fr       */
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

double x_intersection(t_mlx *mlx, double ray_ang, t_test    *pos, t_cord  *p)
{
    int check;

    check = get_ray_angle(ray_ang, 1);
    printf("[x]%d %f\n", check, ray_ang);
    if (!check)
        return (HUGE_VALF);
    p->ya = TILE * check;
    p->xa = p->ya / -tan(to_radian(ray_ang));
    if (check != -1)
        pos->y = (floor(mlx->ply->ply_y / TILE) * TILE) + TILE;
    else
        pos->y = (floor(mlx->ply->ply_y / TILE) * TILE);
    pos->x = mlx->ply->ply_x + (mlx->ply->ply_y - pos->y) 
        / tan(to_radian(ray_ang));
    if(pos->x < 0 || pos->x > mlx->map->map_width * TILE || pos->y < 0 ||
        pos->y > mlx->map->map_height * TILE)
        return (HUGE_VALF);
    if (check == -1)
        pos->y -= 1;
    while ((pos->x / TILE) > - 1 &&  (pos->x / TILE) < mlx->map->map_width &&
        mlx->map->map[(int)(pos->y / TILE)][(int)(pos->x / TILE)] != '1')
    {
        pos->x += p->xa;
        pos->y += p->ya;
    }
    return(sqrt(pow((mlx->ply->ply_x - pos->x), 2) +
        pow((mlx->ply->ply_y - pos->y), 2)));
}

double y_intersection(t_mlx *mlx, double ray_ang, t_test    *pos, t_cord *p)
{
    int check;

    check = get_ray_angle(ray_ang, 2);
    printf("[y]%d %f\n", check, ray_ang);
    exit(0);
    if (!check)
        return (HUGE_VALF);
    p->xa = TILE * check;
    p->ya = p->xa * -tan(to_radian(ray_ang));
    if (check != -1)
        pos->x = (floor(mlx->ply->ply_x / TILE) * TILE) + TILE;
    else
        pos->x = (floor(mlx->ply->ply_x / TILE) * TILE);
    pos->y = mlx->ply->ply_y + (mlx->ply->ply_x - pos->x) *
        tan(to_radian(ray_ang));
    if(pos->x < 0 || pos->x > mlx->map->map_width * TILE ||
        pos->y < 0 || pos->y > mlx->map->map_height * TILE)
        return (HUGE_VALF);
    if (check == -1)
        pos->x -= 1;
    while ((pos->y / TILE) > - 1 &&  (pos->y / TILE) < mlx->map->map_height &&
        mlx->map->map[(int)(pos->y / TILE)][(int)(pos->x / TILE)] != '1')
    {
        pos->x += p->xa;
        pos->y += p->ya;
    }
    return (sqrt(pow((mlx->ply->ply_x - pos->x), 2) +
        pow((mlx->ply->ply_y - pos->y), 2)));
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
    t_cord  pxa;
    t_cord  pya;

    x_distance = x_intersection(mlx, ray_angl, &posx, &pxa);
    y_distance = y_intersection(mlx, ray_angl, &posy, &pya);
    if (y_distance >= x_distance)
        return(normalize_ray(x_distance, ray_angl, mlx));
    else
        return(normalize_ray(y_distance, ray_angl, mlx));
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