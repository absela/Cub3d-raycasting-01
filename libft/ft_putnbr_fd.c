/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:40:24 by absela            #+#    #+#             */
/*   Updated: 2021/11/21 03:53:38 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	y;

	y = nb;
	if (y < 0)
	{
		ft_putchar_fd('-', fd);
		y *= -1;
	}
	if (y > 9)
	{
		ft_putnbr_fd(y / 10, fd);
		ft_putnbr_fd(y % 10, fd);
	}
	else
		ft_putchar_fd(y + 48, fd);
}
