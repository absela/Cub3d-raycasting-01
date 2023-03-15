/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:07:19 by absela            #+#    #+#             */
/*   Updated: 2021/12/02 20:53:28 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	k;

	k = (char) c;
	l = ft_strlen((char *)s);
	while (l >= 0)
	{
		if (k == s[l])
			return ((char *)(s + l));
		l--;
	}
	return (0);
}
