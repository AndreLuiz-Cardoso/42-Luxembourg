/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:33:41 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/01 16:33:42 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_tiny *tiny)
{
	char	*token_aux;
	bool	home;

	home = there_is_home(tiny);
	if (tiny->tokens[1])
		token_aux = ft_strdup(tiny->token.to_print);
	else
	{
		if (home == true)
			token_aux = ft_strdup(tiny->home);
		else
		{
			tiny->last_exit_cmd = 1;
			printf(ERROR_HOME);
			return (1);
		}
	}
	tiny->last_exit_cmd = chdir(token_aux);
	if (tiny->last_exit_cmd == -1)
		printf("minishell: cd: %s: %s", tiny->tokens[1], ERROR_DIR);
	free(token_aux);
	return (0);
}

bool	there_is_home(t_tiny *tiny)
{
	if (find_env(tiny, "HOME"))
		return (true);
	else
		return (false);
}
