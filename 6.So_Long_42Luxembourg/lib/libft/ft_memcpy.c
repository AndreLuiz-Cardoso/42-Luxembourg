/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:07:57 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/20 16:09:19 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	size_t			i;

	destcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (!dst || !src)
	{
		return (dst);
	}
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (destcpy);
}
