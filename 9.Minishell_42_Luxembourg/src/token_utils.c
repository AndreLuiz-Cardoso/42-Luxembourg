/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:38:44 by ancardos          #+#    #+#             */
/*   Updated: 2024/11/01 16:38:46 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_home_sign(t_tiny *tiny, t_token *tk)
{
	char	*extend;

	tk->new = substr_ft(tiny->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	extend = tiny->home;
	tk->end = ft_strjoin(tk->end, extend);
	tk->i++;
	tk->len = 1;
	tk->init = tk->i;
}

void	get_dollar_sign(t_tiny *tiny, t_token *tk)
{
	char	*extend;
	char	*n_env;

	tk->new = substr_ft(tiny->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	tk->posic = tokent(&tiny->line[tk->i + 1], ' ');
	n_env = substr_ft(tiny->line, tk->i + 1, tk->posic);
	if (tiny->line[tk->i + 1] != '?' && find_env(tiny, n_env))
		extend = ft_strdup(find_env(tiny, n_env));
	else if (tiny->line[tk->i + 1] == '?')
		extend = ft_itoa(tiny->last_exit_cmd);
	else
		extend = NULL;
	if (extend)
		tk->end = ft_strjoin(tk->end, extend);
	free(extend);
	tk->i += ft_strlen(n_env) + 1;
	free(n_env);
	tk->len = 1;
	tk->init = tk->i;
}

t_token	*init_tk(void)
{
	t_token	*tk;

	tk = (t_token *)malloc(sizeof(t_token));
	tk->end = NULL;
	tk->new = NULL;
	tk->to_exec = NULL;
	tk->to_print = NULL;
	tk->quote = '\0';
	tk->i = 0;
	tk->init = 0;
	tk->len = 1;
	tk->posic = 0;
	return (tk);
}

void	free_tk(t_token *tk)
{
	if (tk->end != NULL)
	{
		free(tk->end);
		tk->end = NULL;
	}
	if (tk->new != NULL)
	{
		free(tk->new);
		tk->new = NULL;
	}
	if (tk->to_exec != NULL)
	{
		free(tk->to_exec);
		tk->to_exec = NULL;
	}
	if (tk->to_print != NULL)
	{
		free(tk->to_print);
		tk->to_print = NULL;
	}
	free(tk);
}

void	finish_tokenizer(t_tiny *tiny, t_token *tk)
{
	tk->new = substr_ft(tiny->line, tk->init, tk->len);
	tk->end = ft_strjoin(tk->end, tk->new);
	tk->posic = tokent(tk->end, ' ');
	tiny->token.to_print = ft_strtrim(&(tk->end)[tk->posic], " ");
	tiny->token.to_exec = substr_ft(tk->end, tk->i + 1, tk->posic);
	simple_quotes(tiny, tiny->token.to_print, 0, 0);
	tiny->tokens = ft_split(tk->end, ' ');
	free_tk(tk);
	free(tiny->line);
}
