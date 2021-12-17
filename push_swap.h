/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:21:41 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/16 04:29:17 by lshonta          ###   ########.fr       */
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

typedef struct	s_struct
{
	int			value;
	int			index;
	t_struct	*next;
}	t_struct;

void	ft_put_err(char *str, int fd);
void	ft_check(t_support *data);

#endif