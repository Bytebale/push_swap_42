/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:43:11 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 13:42:58 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_bits(t_list **stack)
{
	t_list	*top;
	int		max;
	int		bits;

	top = *stack;
	max = top->index;
	bits = 0;
	while (top)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	top_a = *stack_a;
	size = ft_lstsize(top_a);
	max_bits = ft_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *stack_a;
			if (((top_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}