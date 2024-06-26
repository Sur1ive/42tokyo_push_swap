/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:29:33 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 17:41:53 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	if (*a == NULL)
		return ;
	*a = (*a)->next;
}

void	ra(int n, t_stack **a)
{
	while (n-- > 0)
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

void	rb(int n, t_stack **b)
{
	while (n-- > 0)
	{
		rotate(b);
		ft_printf("rb\n");
	}
}

void	rr(int n, t_stack **a, t_stack **b)
{
	while (n-- > 0)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
}
