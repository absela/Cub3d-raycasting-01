/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:27:49 by absela            #+#    #+#             */
/*   Updated: 2023/04/01 22:05:59 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int every_frame(t_mlx *mlx)
{
    move_ply(mlx);
    rotate_player(mlx);
    mlx_clear_window(mlx->mlx, mlx->mlx_win);
    mlx_destroy_image(mlx->mlx, mlx->img->img);
    mlx->img->img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
    mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length, &mlx->img->endian);
    // draw_world_2d(mlx);
    sky_and_floor(mlx);
    cast_all_rays(mlx);
    // rendar_3dwall(mlx);
    render_walls3d(mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
    return(0);
}


int main(int ac, char **av)
{
    t_mlx *mlx;
    (void)ac;

    mlx = malloc(sizeof(t_mlx));
    init_all(mlx, av);
    mlx_loop_hook(mlx->mlx, every_frame, mlx);
    mlx_hook(mlx->mlx_win, 2, 0, on_keydown, mlx);
	mlx_hook(mlx->mlx_win, 3, 0, on_keyup, mlx);
    // mlx_hook(mlx->mlx_win, 6, 0, on_mousemove, mlx);
    mlx_loop(mlx->mlx);
    return (0);
    
}