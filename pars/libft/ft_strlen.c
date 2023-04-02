/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:06:57 by abelahce          #+#    #+#             */
/*   Updated: 2023/03/10 02:30:52 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}
