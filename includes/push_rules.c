/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:34:38 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 13:40:54 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_rule(t_list **stack_to, t_list **stack_fm)
{
	t_list	*tmp;
	t_list	*top_to;
	t_list	*top_fm;

	if (ft_lstsize(*stack_fm) == 0)
		return (-1);
	top_to = *stack_to;
	top_fm = *stack_fm;
	tmp = top_fm;
	top_fm = top_fm->next;
	*stack_fm = top_fm;
	if (!top_to)
	{
		top_to = tmp;
		top_to->next = NULL;
		*stack_to = top_to;
	}
	else
	{
		tmp->next = top_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push_rule(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push_rule(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}
