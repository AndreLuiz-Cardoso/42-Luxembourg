/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:36:55 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/01 16:36:56 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_path(t_tiny *tiny)
{
	char	*path_aux;
	int		i;

	path_aux = ft_strdup(find_env(tiny, "PATH"));
	if (!path_aux)
		return (0);
	tiny->path = ft_split(path_aux, ':');
	i = 0;
	while (tiny->path && tiny->path[i])
	{
		tiny->path[i] = ft_strjoin(tiny->path[i], "/");
		i++;
	}
	free(path_aux);
	return (1);
}
