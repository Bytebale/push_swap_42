/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:36:02 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/25 22:03:43 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rule(t_list **stack)
{
	t_list	*head;
	t_list	*remain;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	remain = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	remain->next = *stack;
	*stack = remain;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rule(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rule(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rule(stack_a);
	reverse_rule(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}