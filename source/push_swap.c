/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:34:09 by lshonta           #+#    #+#             */
/*   Updated: 2022/01/12 16:44:30 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_make_stack(t_list **stack, t_support *data)
{
	t_list	*new_list;

	data->i = 1;
	while (data->argv[data->i])
	{
		new_list = ft_lstnew(ft_atoi(data->argv[data->i]));
		ft_lstadd_back(stack, new_list);
		data->i++;
	}
	ft_put_index(stack);
}

static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		ft_simple(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list		**stack_a;
	t_list		**stack_b;
	t_support	data;

	data.argc = argc;
	data.argv = argv;
	data.i = 0;
	if (argc < 2)
		return (-1);
	ft_check(&data);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_make_stack(stack_a, &data);
	if (ft_stack_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return(0);
	}
	ft_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
