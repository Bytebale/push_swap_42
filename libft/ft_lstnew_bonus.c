/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:19:05 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/27 13:47:37 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(rtn));
	if (!rtn)
		return (NULL);
	rtn->content = content;
	rtn->index = -1;
	rtn->next = NULL;
	return (rtn);
}
