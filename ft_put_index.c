/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:40:27 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/16 05:41:06 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_struct	*ft_get_min_value(t_struct **stack, t_support *data)
{
	t_struct	*top;
	t_struct	*min;
	int			intmin;

	min = NULL;
	intmin = 0;
	top = *stack;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!intmin || top->value < min->value))
			{
				min = top;
				intmin = 1;
			}
			top = top->next;
		}
	}
	return (min);
}

void	ft_put_index(t_struct **stack, t_support *data)
{
	data->i = 0;
	data = ft_get_min_value(stack, data);
	while (data)
	{
		data->i++;
		data = ft_get_min_value(stack, data);
	}
}
