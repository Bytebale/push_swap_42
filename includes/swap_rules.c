/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:07:06 by lshonta           #+#    #+#             */
/*   Updated: 2022/01/13 21:21:50 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_rule(t_list **stack)
{
	t_list	*top;
	t_list	*next;
	int		tmp_val;
	int		tmp_i;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_put_err("Error\n swap!", 1);
	tmp_val = top->content;
	tmp_i = top->index;
	top->content = next->content;
	top->index = next->index;
	next->content = tmp_val;
	next->index = tmp_i;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap_rule(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap_rule(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap_rule(stack_a);
	swap_rule(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
