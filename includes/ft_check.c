/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:48:23 by lshonta           #+#    #+#             */
/*   Updated: 2022/01/12 16:25:32 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_repeat_arg(int nbr, t_support *data, int i)
{
	i++;
	while (data->argv[i])
	{
		if (ft_atoi(data->argv[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *nbr)
{
	int	i;
	
	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check(t_support *data)
{
	
	long		num;

	data->i = 1;
	while (data->argv[data->i])
	{
		num = ft_atoi(data->argv[data->i]); 
		if (!ft_isnum(data->argv[data->i]))
			ft_put_err("error", 1);
		if (ft_repeat_arg(num, data, data->i))
			ft_put_err("error", 1);
		if (num < INT32_MIN || num > INT32_MAX)
			ft_put_err("error", 1);
		data->i++;
	}
	if (data->argc == 2)
		exit(EXIT_FAILURE);
}
