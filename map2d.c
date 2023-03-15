#include "cub3d.h"

void    draw_square(int i, int j, t_mlx *mlx)
{
	int x = j * TILE;
	int y;

	while(x < j * TILE + (TILE - 1))
	{
		y = i * TILE;
		while(y < i * TILE + (TILE - 1))
		{
			my_mlx_pixel_put(mlx->img,x,y, 0x99e6ff);
			y++;
		}
		x++;
	}
}

void    draw_squaref(int i, int j, t_mlx *mlx)
{
	int x = j * TILE;
	int y;

	while(x < j * TILE + (TILE - 1))
	{
		y = i * TILE;
		while(y < i * TILE + (TILE - 1))
		{
			my_mlx_pixel_put(mlx->img,x,y, 0x8D5B4C);
			y++;
		}
		x++;
	}
}

void    draw_world_2d(t_mlx *mlx)
{
	int i = 0;
	int j;
	while(mlx->map->map[i])
	{
		j = 0;
		while(mlx->map->map[i][j])
		{
			if(mlx->map->map[i][j] == '1')
				draw_square(i,j,mlx);
			if(mlx->map->map[i][j] == '0')
				draw_squaref(i,j,mlx);
			j++;
		}
		i++;
	}
}