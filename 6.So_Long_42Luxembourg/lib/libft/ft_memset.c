/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:12:17 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/20 15:12:19 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t count)
{
	unsigned char	*strptr;
	size_t			i;

	strptr = (unsigned char *)str;
	i = 0;
	while (i < count)
	{
		strptr[i] = (unsigned char)value;
		i++;
	}
	return (str);
}
