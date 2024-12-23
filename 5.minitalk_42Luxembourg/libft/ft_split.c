/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:43:05 by ancardos          #+#    #+#             */
/*   Updated: 2024/02/23 13:50:23 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	ft_bzero(mem, size);
	return (mem);
}

int	ft_countwords(const char *string, char c)
{
	int	nbr;

	nbr = 0;
	while (*string)
	{
		while (*string == c)
			string++;
		if (*string != '\0')
		{
			nbr++;
			while (*string != c && *string != '\0')
				string++;
		}
	}
	return (nbr);
}

int	ft_lword(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**new;

	j = 0;
	i = 0;
	new = ft_memalloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			new[j] = ft_memalloc(sizeof(char) * (ft_lword(s, c) + 1));
			while (*s != c && *s != '\0')
				new[j][i++] = (char)*s++;
			new[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	new[j] = NULL;
	return (new);
}
