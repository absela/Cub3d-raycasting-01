/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:04:51 by absela            #+#    #+#             */
/*   Updated: 2021/11/21 05:22:14 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	int		i;
	char	*ptr;
	char	*str;

	ptr = (char *) dst;
	str = (char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		ptr[i] = str[i];
		i++;
	}
	return (dst);
}
