/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:55:41 by absela            #+#    #+#             */
/*   Updated: 2021/12/02 20:47:22 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr(long long n, int len, char *r)
{
	while (n)
	{
		r[len] = 48 + (n % 10);
		n /= 10;
		len--;
	}
}

static int	ft_len(int n)
{
	int	d;

	d = 0;
	if (n < 0)
		d++;
	while (n != 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			size;
	char		*r;

	size = ft_len(n);
	if (!size)
	{
		r = (char *)malloc(2);
		r[0] = '0';
		r[1] = '\0';
		return (r);
	}
	r = malloc(size * sizeof(char) + 1);
	if (!r)
		return (NULL);
	r[size] = '\0';
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		r[0] = '-';
	}
	ft_nbr(nb, size - 1, r);
	return (r);
}
