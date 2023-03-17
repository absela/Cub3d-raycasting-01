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

void sky(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while(x < mlx->win_width)
	{
		y = 0;
		while(y < mlx->win_height / 2)
		{
			my_mlx_pixel_put(mlx->img,x,y, 0x99e6ff);
			y++;
		}
		x++;
	}
}

void floorxx(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while(x < mlx->win_width)
	{
		y = mlx->win_height / 2;
		while(y < mlx->win_height)
		{
			my_mlx_pixel_put(mlx->img,x,y, 0x8D5B4C);
			y++;
		}
		x++;
	}
}

void rend_3D(t_mlx *mlx)
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
			j++;
		}
		i++;
	}
}


void	render_slice(t_mlx *mlx, int slice, int x)
{
	int				y;
	unsigned int	color;

	color = 255;
	y = (mlx->win_height / 2) - (slice / 2);
	if (y < 0)
		y = 0;
	while (y <= (mlx->win_height / 2) + (slice / 2))
	{
		my_mlx_pixel_put(mlx->img, x, y, color);
		if (y > mlx->win_height)
			break ;
		y++;
	}
}

void	render_walls3d(t_mlx *mlx)
{
	int	slice;
	int	i;

	i = 0;
	while (i <= mlx->win_width - 1)
	{
		slice = ((double)TILE / mlx->rays[i].distance) * mlx->pro_plane;
		render_slice(mlx, slice, i);
		i++;
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