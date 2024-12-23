/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:02:48 by ancardos          #+#    #+#             */
/*   Updated: 2024/07/23 17:02:49 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

static int	calculate_max_index_bits(t_stack **stack)
{
	t_stack	*current_node;
	int		max;
	int		max_b;

	current_node = *stack;
	max = current_node->index;
	max_b = 0;
	while (current_node)
	{
		if (current_node->index > max)
			max = current_node->index;
		current_node = current_node->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

void	radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*lst;
	int		i;
	int		j;
	int		size;
	int		max_b;

	i = 0;
	size = get_stack_size(*a_stack);
	max_b = calculate_max_index_bits(a_stack);
	while (i < max_b)
	{
		j = 0;
		while (j < size)
		{
			lst = *a_stack;
			if (((lst->index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
			j++;
		}
		while (*b_stack)
			pa(a_stack, b_stack);
		i++;
	}
}
