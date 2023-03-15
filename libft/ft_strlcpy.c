/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:03:31 by absela            #+#    #+#             */
/*   Updated: 2021/11/20 22:05:00 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	o;
	size_t	i;

	o = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while ((src[o] != '\0') && (o < dstsize - 1))
	{
		dst[o] = src[o];
		o++;
	}
	dst[o] = '\0';
	return (i);
}
