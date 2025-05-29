/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:33:19 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/01 16:33:20 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(t_tiny *tiny, char *needle)
{
	int	i;
	int	len;
	int	len_needle;

	i = 0;
	tiny->env.index = 0;
	len_needle = ft_strlen(needle);
	while (tiny->env.key[i] && i < tiny->env.len)
	{
		len = ft_strlen(tiny->env.key[i]);
		if (!ft_strncmp(tiny->env.key[i], needle, len_needle)
			&& len == len_needle)
		{
			tiny->env.index = i;
			return (tiny->env.content[i]);
		}
		i++;
	}
	return (0);
}
