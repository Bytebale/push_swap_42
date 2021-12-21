/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:34 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/21 21:36:20 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_err(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	exit (0);
}

void	ft_free_stack(t_struct **stack)
{
	t_struct	*top;
	t_struct	*tmp;

	top = *stack;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(stack);
}

int	ft_stack_sorted(t_struct	**stack)
{
	t_struct	*top;
	
	top = *stack;
	while (top && top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

int	ft_stack_size(t_struct *top)
{
	size_t		i;
	t_struct	*tmp;

	tmp = top;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}