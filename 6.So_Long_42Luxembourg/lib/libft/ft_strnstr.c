/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:07 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/21 15:44:03 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	i;

	i = 0;
	pos = 0;
	if (!*little)
		return ((char *)big);
	while (big[pos] && len)
	{
		i = 0;
		if (little[i] == big[pos + i])
		{
			while (little[i] == big[pos + i] && i < len)
			{
				i++;
				if (little[i] == '\0')
					return ((char *)&big[pos]);
			}
		}
		pos++;
		len--;
	}
	return (NULL);
}
