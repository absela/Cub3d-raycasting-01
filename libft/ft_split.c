/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:52:19 by absela            #+#    #+#             */
/*   Updated: 2021/11/24 07:52:37 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checksper(char c, char sep)
{
	if (c == sep)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	countw(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (checksper(str[i], c) == 0 && checksper(str[i + 1], c) == 1)
			w++;
		i++;
	}
	return (w);
}

static void	cpyw(char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while (checksper(s2[i], c) == 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static int	ft_split1(char **split, char *str, char c, int k)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if (checksper(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (checksper(str[i + j], c) == 0)
				j++;
			split[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split + k))
				return (0);
			cpyw(split[k], str + i, c);
			i += j;
			k++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**st;
	int			w;

	if (!s)
		return (NULL);
	st = (char **)malloc(sizeof(char *) * (countw((char *)s, c) + 1));
	if (!st)
		return (NULL);
	w = 0;
	if (!ft_split1(st, (char *)s, c, 0))
	{
		while (st + w)
		{
			free(st + w);
			w++;
		}
		free(st);
	}
	st[countw((char *)s, c)] = 0;
	return (st);
}
