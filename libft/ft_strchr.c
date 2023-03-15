/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:32:56 by absela            #+#    #+#             */
/*   Updated: 2021/11/21 01:36:03 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		l;
	int		i;
	char	k;

	k = (char) c;
	l = ft_strlen((char *)s);
	i = 0;
	while (l >= i)
	{
		if (k == s[i])
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
