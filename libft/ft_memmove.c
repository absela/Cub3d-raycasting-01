/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:36:40 by absela            #+#    #+#             */
/*   Updated: 2021/11/22 08:12:13 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dist, const void	*src, size_t	n)
{
	char	*d;
	char	*s;

	d = (char *)dist;
	s = (char *)src;
	if (dist == 0 && src == 0)
		return (0);
	if (d < s)
	{
		while (0 < n--)
			*d++ = *s++;
	}
	else
	{
		while (0 < n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dist);
}
