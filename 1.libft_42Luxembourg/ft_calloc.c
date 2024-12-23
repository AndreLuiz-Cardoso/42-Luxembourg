/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:23:47 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/22 13:25:32 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)s;
	while (n > 0)
	{
		*tmp_ptr = 0;
		tmp_ptr++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	total;

	total = count * size;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (total / count != size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
