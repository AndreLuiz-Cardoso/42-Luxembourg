/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:56:14 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/22 16:14:39 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		res[i + k] = s2[k];
		k++;
	}
	res[i + k] = '\0';
	return (res);
}
