/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:02:18 by ancardos          #+#    #+#             */
/*   Updated: 2024/07/23 17:02:19 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_addfront(t_stack **stack, t_stack *news)
{
	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	(*stack)->prev = news;
	news->next = *stack;
	*stack = news;
	news->prev = NULL;
}

void	lst_addback(t_stack **stack, t_stack *news)
{
	t_stack	*tmp;

	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
	news->prev = tmp;
}

t_stack	*lst_new(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->index = -1;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*lst_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
