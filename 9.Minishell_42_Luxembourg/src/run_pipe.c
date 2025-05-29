/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:37:49 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/01 16:37:51 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_descriptor_handler(int in, int out)
{
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
	return (0);
}

void	spaces_in_pipe(t_tiny *tiny, int i, char *command)
{
	char	*aux;

	if (ft_strlen(tiny->token.to_print) && tiny->tokens[i]
		&& (tiny->tokens[i][0] == QUOTE || tiny->tokens[i][0] == D_QUOTE)
		&& ft_strncmp(tiny->tokens[i - 1], "sed", 3))
	{
		aux = ft_strtrim(tiny->token.to_print, D_QUOTE_S);
		free_char_array2(&tiny->tokens[i + 1]);
	}
	else
		aux = ft_strtrim(tiny->tokens[i], D_QUOTE_S);
	free(tiny->tokens[i]);
	tiny->tokens[i] = aux;
	command = ft_strjoin(command, tiny->tokens[i - 1]);
	tiny->last_exit_cmd = execve(command, &tiny->tokens[i - 1], tiny->env.env);
	free(command);
}

void	execve_error(t_tiny *tiny)
{
	tiny->last_exit_cmd = 127;
	if (tiny->tokens[0][0] != '|')
		printf("minishell: %s: %s", tiny->tokens[0], ERROR_CMD);
	else if (tiny->tokens[1])
		printf("minishell: %s: %s", tiny->tokens[1], ERROR_CMD);
}
