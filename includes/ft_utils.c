/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:34 by lshonta           #+#    #+#             */
/*   Updated: 2022/01/13 22:33:23 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_put_err(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	exit (0);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*top;
	t_list	*tmp;

	top = *stack;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(stack);
}

int	ft_stack_sorted(t_list	**stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (top->content > top->next->content)
			return (0);
		top = top->next;
	}
	return (1);
}

int	ft_dist_to_num(t_list **stack, int i)
{
	t_list	*top;
	int		dist;

	dist = 0;
	top = *stack;
	while (top)
	{
		if (top->index == i)
			break ;
		dist++;
		top = top->next;
	}
	return (dist);
}

void	sort_utils(t_list **stack_a, t_list *top, int min)
{
	if (top->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}
