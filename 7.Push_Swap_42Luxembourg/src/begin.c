/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:41:31 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/05 17:41:33 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_stackclear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ps_stackclear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

int	ps_check_dup(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (-1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

void	print_error(t_stack **a_stack)
{
	ft_putstr_fd("Error\n", 2);
	ps_stackclear(a_stack);
	exit(1);
}
