/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:34 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/25 22:13:22 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_put_err(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	exit (0);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	top = *stack;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(stack);
}

int	ft_stack_sorted(t_stack	**stack)
{
	t_stack	*top;
	
	top = *stack;
	while (top && top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

int ft_disToNum(t_stack **stack, int i)
{
	t_stack *top;
	int		dist;

	dist = 0;
	top = *stack;
	while (top)
	{
		if (top->index = i)
			break ;
		dist++;
		top = top->next;
	}
	return (dist);
}