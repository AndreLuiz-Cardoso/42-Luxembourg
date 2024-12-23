/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:32:05 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/21 14:33:12 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_s = (unsigned char *)s;
	i = 0;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (ptr_s[i] == c1)
			return (&ptr_s[i]);
		i++;
	}
	return (NULL);
}
