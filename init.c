/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:16:01 by absela            #+#    #+#             */
/*   Updated: 2023/03/17 10:34:58 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_height(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void pos_ply(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (mlx->map->map[i])
    {
        j = 0;
        while (mlx->map->map[i][j])
        {
            if (mlx->map->map[i][j] == 'N')
            {
                mlx->ply->player_pos_x = (double)((j * TILE) + TILE / 2);
                mlx->ply->player_pos_y = (double)((i * TILE) + TILE / 2);
            }
            j++;
        }
        i++;
    }
}

void init_ply(t_mlx *mlx)
{
    pos_ply(mlx);
    mlx->ply->field_of_view = 60;
    mlx->ply->ply_angle = 90;
    mlx->ply->turn_direction = 0;
    mlx->ply->walk_direction = 0;
}

int on_mousemove(int x, int y, t_mlx *mlx)
{
    (void)y;
    mlx->ply->ply_angle = (double)(x * 0.09);
    mlx->ply->ply_angle = angl_limit(mlx->ply->ply_angle);
    return (0);
}


void init_all(t_mlx **mlx, char **av)
{
    *mlx = malloc(sizeof(t_mlx));
    (*mlx)->map = malloc(sizeof(t_map));
    (*mlx)->img = malloc(sizeof(t_data));
    (*mlx)->ply = malloc(sizeof(t_ply));
    (*mlx)->map->map = r_map(av[1]);
    init_ply(*mlx);
    (*mlx)->mlx = mlx_init();
    (*mlx)->map->map_width = ft_strlen((*mlx)->map->map[0]);
    (*mlx)->map->map_height = map_height((*mlx)->map->map);
    (*mlx)->win_width = W_WITH;
    (*mlx)->win_height = W_HEIGHT;
    (*mlx)->angle_btw_rays = (*mlx)->ply->field_of_view / (double)(*mlx)->win_width;
    (*mlx)->pro_plane = ((*mlx)->win_width / 2) / tan(to_radian((*mlx)->ply->field_of_view / 2));
    (*mlx)->mlx_win = mlx_new_window((*mlx)->mlx, (*mlx)->win_width, (*mlx)->win_height, "cub3d");
    (*mlx)->img->img = mlx_new_image((*mlx)->mlx, (*mlx)->win_width, (*mlx)->win_height);
    (*mlx)->img->addr = mlx_get_data_addr((*mlx)->img->img, &(*mlx)->img->bits_per_pixel, &(*mlx)->img->line_length, &(*mlx)->img->endian);
}