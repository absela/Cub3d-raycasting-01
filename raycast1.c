/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:26:30 by absela            #+#    #+#             */
/*   Updated: 2023/03/15 09:29:17 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_ray_angle(double ray_ang, int flag)
{
    if (flag == 1)
    {
        if (ray_ang == 0 || ray_ang == 180)
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

double x_intersection(t_mlx *mlx, double ray_ang)
{
    int check;
    double xa;
    double ya;
    double y_intersection;
    double x_intersection;
    double distance;

    check = get_ray_angle(ray_ang, 1);
    if (!check)
        return (HUGE_VALF);
    if (check != -1)
        y_intersection = (roundf(mlx->ply->player_pos_y / TILE) * TILE) + TILE;
    else
        y_intersection = (roundf(mlx->ply->player_pos_y / TILE) * TILE) - 1;
    x_intersection = mlx->ply->player_pos_x + (mlx->ply->player_pos_y - y_intersection) / tan(to_radian(ray_ang));
    ya = TILE * check;
    xa = ya / -tan(to_radian(ray_ang));
    distance = 0;
    while ((x_intersection / TILE) > - 1 &&  (x_intersection / TILE) < mlx->map->map_width && mlx->map->map[(int)(y_intersection / TILE)][(int)(x_intersection / TILE)] != '1')
    {
        x_intersection += xa;
        y_intersection += ya;
    }
    distance = sqrt(pow((mlx->ply->player_pos_x - x_intersection), 2) + pow((mlx->ply->player_pos_y - y_intersection), 2));
    dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,x_intersection ,y_intersection, 0, 0, 0x00FF00);

    return (distance);
}

double y_intersection(t_mlx *mlx, double ray_ang)
{
    int check;
    double xa;
    double ya;
    double y_intersection;
    double x_intersection;
    double distance;

    check = get_ray_angle(ray_ang, 2);
    if (!check)
        return (HUGE_VALF);
    if (check != -1)
        x_intersection = (roundf(mlx->ply->player_pos_x / TILE) * TILE) + TILE;
    else
        x_intersection = (roundf(mlx->ply->player_pos_x / TILE) * TILE) - 1;
    y_intersection = mlx->ply->player_pos_y + (mlx->ply->player_pos_x - x_intersection) *  tan(to_radian(ray_ang));
    xa = TILE * check;
    ya = xa / -tan(to_radian(ray_ang));
    distance = 0;
    while ((y_intersection / TILE) > - 1 &&  (y_intersection / TILE) < mlx->map->map_height && mlx->map->map[(int)(y_intersection / TILE)][(int)(x_intersection / TILE)] != '1')
    {
        x_intersection += xa;
        y_intersection += ya;
    }
    distance = sqrt(pow((mlx->ply->player_pos_x - x_intersection), 2) + pow((mlx->ply->player_pos_y - y_intersection), 2));
    // dda(mlx, mlx->ply->player_pos_x, mlx->ply->player_pos_y,x_intersection ,y_intersection, 0, 0, 0xFF0000);

    return (distance);
}

double  cast_ray(t_mlx *mlx, double ray_angl)
{
    double x_distance;
    double y_distance;

    x_distance = x_intersection(mlx, ray_angl);
    y_distance = y_intersection(mlx, ray_angl);
    if (y_distance > x_distance)
    {
        return (x_distance);
    }
    else
    {
        return (y_distance);
    }
    return (0);
}

void cast_all_rays(t_mlx *mlx)
{
    int i;
    int x;
    double ray_angl;

    i = 0;
    x = mlx->win_width;
    mlx->rays = malloc(sizeof(t_ray) * x);
    while (i < x)
    {
        ray_angl = mlx->ply->ply_angle + (mlx->ply->field_of_view / 2) - (mlx->angle_btw_rays * (double)i);
        ray_angl = angl_limit(ray_angl);
        mlx->rays[i].ray_angle = ray_angl;
        mlx->rays[i].distance = cast_ray(mlx, mlx->ply->ply_angle);
        i++;
    }
    // getchar();

}