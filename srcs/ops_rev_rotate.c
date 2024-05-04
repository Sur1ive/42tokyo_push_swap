/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:37:08 by yxu               #+#    #+#             */
/*   Updated: 2024/05/04 13:44:24 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **a)
{
	if (*a == NULL)
		return ;
	*a = (*a)->prev;
}

void	rra(int n, t_stack **a)
{
	while (n-- > 0)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void	rrb(int n, t_stack **b)
{
	while (n-- > 0)
	{
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

void	rrr(int n, t_stack **a, t_stack **b)
{
	while (n-- > 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_printf("rrr\n");
	}
}
