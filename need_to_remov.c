#include "cub3d.h"

char	**r_map(char	*str)
{
	int		check;
	int		fd;
	char	*buf;
	char	*map;
	char    **res;

	map = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("unable to open the map!!\n");
		exit(1);
	}
	buf = malloc(2);
	check = read(fd, buf, 1);
	buf[1] = '\0';
	while (check > 0)
	{
		map = ft_strjoin(map, buf);
		check = read(fd, buf, 1);
		buf[1] = '\0';
	}
	free(buf);
	res = ft_split(map, '\n');
	return (res);
}

double to_radian(double n)
{
	return (n * M_PI / 180);
}

// void dda(t_mlx *data, double X0, double Y0, double X1, double Y1, double angle, double scale,int color)
// {
// 	angle = 0;
// 	scale = 0;
//     double dx = X1 - X0;
//     double dy = Y1 - Y0;

//     double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
//     //printf("steps is : %f\n",steps);
//     double Xinc = dx / (double)steps;
//     double Yinc = dy / (double)steps;
//     for (int i = 0; i <= steps; i++)
//     {
//         my_mlx_pixel_put(data->img,X0,Y0,color);
//         X0 += Xinc;
//         Y0 += Yinc;
//     }
// }


void dda(t_mlx *data, double X0, double Y0, double X1, double Y1, double angle, double scale,int color)
{
	(void)scale;
	(void)angle;
    double dx = X1 - X0;
    double dy = Y1 - Y0;

    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    //printf("steps is : %f\n",steps);
    double Xinc = dx / (double)steps;
    double Yinc = dy / (double)steps;
    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(data->img,X0,Y0,color);
        X0 += Xinc;
        Y0 += Yinc;
		// usleep(20);
    }
}