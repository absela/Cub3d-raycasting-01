/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:13:30 by absela            #+#    #+#             */
/*   Updated: 2021/12/02 21:06:03 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*src ;

	src = (unsigned char *)str;
	while (n-- > 0)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return ((void *)0);
}	
