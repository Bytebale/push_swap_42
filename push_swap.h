/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:21:41 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/25 22:07:34 by lshonta          ###   ########.fr       */
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

typedef struct	s_stack
{
	int					value;
	int					index;
	struct s_stack		*next;
}	t_stack;

void	ft_put_err(char *str, int fd);
void	ft_check(t_support *data);
void	ft_free_stack(t_stack **stack);
int		ft_stack_sorted(t_stack **stack);
int 	ft_disToNum(t_stack **stack, int i);
void	ft_simple(t_stack **stack_a, t_stack **stack_b);
void	sort_5nbr(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);

int	push_rule(t_stack **stack_to, t_stack **stack_from);
int	pb(t_stack **stack_a, t_stack **stack_b);
int	pa(t_stack **stack_a, t_stack **stack_b);

int	swap_rule(t_stack **stack);
int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack **stack_a, t_stack **stack_b);

int	rotate_rule(t_stack **stack);
int	rb(t_stack **stack_b);
int	ra(t_stack **stack_a);
int	rr(t_stack **stack_a, t_stack **stack_b);

int	reverse_rule(t_list **stack);
int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);




#endif