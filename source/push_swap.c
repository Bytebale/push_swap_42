/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:34:09 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/25 22:13:14 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_make_stack(t_stack **stack, t_support *data)
{
	t_stack	*new_list;

	data->i = 1;
	while (data->argv[data->i])
	{
		new_list = ft_lstnew(ft_atoi(data->argv[data->i]));
		ft_lstadd_back(stack, new_list);
		data->i++;
	}
	ft_put_index(stack, data);
}

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) < 6)
		ft_simple(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_support	data;

	data.argv = argv;
	data.argc = argc;
	data.i = 0;
	if (argc < 2)
		return (-1);
	ft_check(&data);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
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
