/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:56:15 by absela            #+#    #+#             */
/*   Updated: 2021/11/22 02:34:54 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	sz;

	i = 0;
	j = 0;
	sz = 0;
	j = ft_strlen((char *)dest);
	i = ft_strlen((char *)src);
	if (j >= size)
		sz = i + size;
	else
		sz = i + j;
	i = 0;
	while (src[i] && (j + 1) < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (sz);
}
