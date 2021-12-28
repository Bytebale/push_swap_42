/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:43:14 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 14:26:07 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_min_num(t_list **stack, int num)
{
	t_list	*top;
	int			min_val;

	top = *stack;
	min_val = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min_val) && top->index != num)
			min_val = top->index;
	}
	return (min_val);
}

static void	sort_3nbr(t_list **stack_a)
{
	t_list		*top;
	int			min;
	int			min_next;

	top = *stack_a;
	min = ft_min_num(stack_a, -1);
	min_next = ft_min_num(stack_a, min);
	if (ft_stack_sorted(stack_a))
		return ;
	if (top->index == min && top->next->index != min_next)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (top->index == min_next)
	{
		if (top->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (top->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sort_4nbr(t_list **stack_a, t_list **stack_b)
{
	int num;

	if (ft_stack_sorted(stack_a))
		return ;
	num = ft_distToNum(stack_a, ft_min_num(stack_a, -1));
	if (num == 1)
		ra(stack_a);
	else if (num == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (num == 3)
		rra(stack_a);
	if (ft_stack_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3nbr(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5nbr(t_list **stack_a, t_list **stack_b)
{
	int	num;

	num = ft_distToNum(stack_a, ft_min_num(stack_a, -1));
	if (num == 1)
		ra(stack_a);
	else if (num == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (num == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (num == 4)
		rra(stack_a);
	if (ft_stack_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4nbr(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_simple(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (ft_stack_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3nbr(stack_a);
	else if (size == 4)
		sort_4nbr(stack_a, stack_b);
	else if (size == 5)
		sort_5nbr(stack_a, stack_b);
}