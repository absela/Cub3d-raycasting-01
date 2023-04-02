/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:51:08 by absela            #+#    #+#             */
/*   Updated: 2023/04/01 05:17:17 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int on_keydown(int keycode, t_mlx *mlx)
{
    if (keycode == 13)
        mlx->ply->walk_direction = 1;
    if (keycode == 1)
        mlx->ply->walk_direction = -1;
    if (keycode == 124)
        mlx->ply->turn_direction = -1;
    if (keycode == 123)
        mlx->ply->turn_direction = 1;
    if (keycode == 53)
        exit(0);
    return (0);
}

int on_keyup(int keycode, t_mlx *mlx)
{
    if (keycode == 13 || keycode == 1)
        mlx->ply->walk_direction = 0;
    if (keycode == 123 || keycode == 124)
        mlx->ply->turn_direction = 0;
    return (0);
}

double angl_limit(double ra)
{
    while (ra >= 360.0)
        ra -= 360.0;
    while (ra < 0.0)
        ra += 360.0;
    return ra;
}

void	rotate_player(t_mlx	*mlx)
{
	mlx->ply->ply_angle += mlx->ply->turn_direction * TUSPEED;
	mlx->ply->ply_angle = angl_limit(mlx->ply->ply_angle); 
}

void move_ply(t_mlx *mlx)
{
    double x;
    double y;
    int add_x;
    int add_y;

    x = cos(to_radian(mlx->ply->ply_angle)) * mlx->ply->walk_direction * MVSPEED;
    y = sin(to_radian(mlx->ply->ply_angle)) * mlx->ply->walk_direction * MVSPEED;
    add_x = (mlx->ply->ply_x + x) / TILE;
    add_y = (mlx->ply->ply_y - y) / TILE;
    if (mlx->map->map[(int)(mlx->ply->ply_y - y) / TILE][(int)(mlx->ply->ply_x + x) / TILE] != '1')
    {
        if(mlx->map->map[(int)mlx->ply->ply_y / TILE][add_x] == '1' && mlx->map->map[add_y][(int) mlx->ply->ply_x / TILE] == '1')
            return ;
        mlx->ply->ply_x += x;
        mlx->ply->ply_y -= y;
    }
}