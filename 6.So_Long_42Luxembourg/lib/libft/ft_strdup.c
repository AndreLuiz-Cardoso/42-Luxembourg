/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:40:14 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/22 13:45:44 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*dest;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	int start = atoi(argv[2]);
	int len = atoi(argv[3]);
	char *res = ft_substr(argv[1], start, len);

	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Sending argv[2] = %d\n", start);
	printf("Sending argv[3] = %d\n", len);

	printf("Returning \'%s\'\n", res);
}
 */
