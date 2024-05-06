/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:12:39 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 16:23:13 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	while (tmp != *a)
	{
		if (tmp->prev->content > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_sinfo	genstackinfo(int len, t_stack **stack)
{
	t_sinfo	stackinfo;

	stackinfo.len = len;
	stackinfo.stack = stack;
	return (stackinfo);
}
