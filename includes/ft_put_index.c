/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:40:27 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 14:35:14 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_get_min_value(t_list **stack)
{
	t_list		*top;
	t_list		*min;
	int			intmin;

	min = NULL;
	intmin = 0;
	top = *stack;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!intmin || top->content < min->content))
			{
				min = top;
				intmin = 1;
			}
			top = top->next;
		}
	}
	return (min);
}

void	ft_put_index(t_list **stack)
{
	t_list	*top;
	int		index;

	index = 0;
	top = ft_get_min_value(stack);
	while (top)
	{
		top->index = index++;
		top = ft_get_min_value(stack);
	}
}
