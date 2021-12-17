/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:34:09 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/16 05:41:17 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_stack(t_struct **stack, t_support *data)
{
	t_struct	*new_list;

	data->i = 1;
	while (data->argv[data->i])
	{
		new_list = ft_lstnew(ft_atoi(data->argv[data->i]));
		ft_lstadd_back(stack, new_list);
		data->i++;
	}
	ft_put_index(stack, data);
}

int	main(int argc, char **argv)
{
	t_struct	**stack_a;
	t_struct	**stack_b;
	t_support	*data;

	data->argc = argc;
	data->argv = argv;
	if (argc < 2)
		return (-1);
	ft_check(data);
	stack_a = (t_struct **)malloc(sizeof(t_struct));
	stack_b = (t_struct **)malloc(sizeof(t_struct));
	ft_make_stack(stack_a, data);
}
