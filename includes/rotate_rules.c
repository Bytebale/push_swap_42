/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:35:20 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/25 22:03:52 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_rule(t_stack **stack)
{
	t_stack	*head;
	t_stack	*remain;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	remain = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	remain->next = head;
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate_rule(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate_rule(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate_rule(stack_a);
	rotate_rule(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
