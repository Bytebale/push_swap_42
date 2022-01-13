/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:21:41 by lshonta           #+#    #+#             */
/*   Updated: 2022/01/13 22:32:40 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <inttypes.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_support
{
	int			argc;
	int			i;
	char		**argv;
}	t_support;

void	ft_put_err(char *str, int fd);
void	ft_check(t_support *data);
void	ft_free_stack(t_list **stack);
int		ft_stack_sorted(t_list	**stack);
int		ft_dist_to_num(t_list **stack, int i);
void	ft_put_index(t_list **stack);
void	ft_simple(t_list **stack_a, t_list **stack_b);
void	sort_5nbr(t_list **stack_a, t_list **stack_b);
void	ft_radix(t_list **stack_a, t_list **stack_b);
void	sort_utils(t_list **stack_a, t_list *top, int min);

int		push_rule(t_list **stack_to, t_list **stack_from);
int		pb(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);

int		swap_rule(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

int		rotate_rule(t_list **stack);
int		rb(t_list **stack_b);
int		ra(t_list **stack_a);
int		rr(t_list **stack_a, t_list **stack_b);

int		reverse_rule(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif