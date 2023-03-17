/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:43:01 by absela            #+#    #+#             */
/*   Updated: 2023/03/17 10:34:48 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if ((x >= 0 && x < (W_WITH)) && (y >= 0 && y < W_HEIGHT))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

// void	pixel_put_img(t_img *img, int x, int y, unsigned int color)
// {
// 	char	*dst;

// 	if ((x >= 0 && x < (P_W * SSCL)) && (y >= 0 && y < P_H * SSCL))
// 	{
// 		dst = img->addr + (y * img->len + x * (img->bpp / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }