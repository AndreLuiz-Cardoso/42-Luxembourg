/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:38:51 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/04 11:38:54 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_tiny *tiny)
{
	char	*buf;

	buf = get_cwd_buf();
	ft_putendl_fd(buf, tiny->out_fd);
	if (buf == NULL)
		tiny->last_exit_cmd = 1;
	else
		tiny->last_exit_cmd = 0;
	free(buf);
}

char	*get_cwd_buf(void)
{
	size_t	size;
	char	*buf;

	size = 2000;
	buf = NULL;
	buf = getcwd(buf, size);
	return (buf);
}
