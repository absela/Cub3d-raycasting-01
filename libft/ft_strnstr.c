/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 05:28:03 by absela            #+#    #+#             */
/*   Updated: 2021/11/20 09:00:06 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (ft_strlen((char *)s2) > ft_strlen((char *)s1))
		return (0);
	if (s2 == NULL || ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if ((size_t) ft_strlen((char *)s2) > n)
		return (NULL);
	while (i < n)
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen((char *)s2)) == 0)
		{
			if (i + ft_strlen((char *)s2) > n)
				return (NULL);
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
