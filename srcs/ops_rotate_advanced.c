/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_advanced.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:47:11 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 11:07:38 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_ia_to_top(int i, t_sinfo a)
{
	if (a.len - i > i)
		ra(i, a.stack);
	else
		rra(a.len - i, a.stack);
}

void	rotate_ib_to_top(int i, t_sinfo b)
{
	if (b.len - i > i)
		rb(i, b.stack);
	else
		rrb(b.len - i, b.stack);
}

static void	rotate_iaib_up(int ia, int ib, t_stack **a, t_stack **b)
{
	if (ia < ib)
	{
		rr(ia, a, b);
		rb(ib - ia, b);
	}
	else
	{
		rr(ib, a, b);
		ra(ia - ib, a);
	}
}

static void	rotate_iaib_down(int ia, int ib, t_sinfo a, t_sinfo b)
{
	if (a.len - ia < b.len - ib)
	{
		rrr(a.len - ia, a.stack, b.stack);
		rrb(b.len - ib - a.len + ia, b.stack);
	}
	else
	{
		rrr(b.len - ib, a.stack, b.stack);
		rra(a.len - ia - b.len + ib, a.stack);
	}
}

void	rotate_iaib_to_top(int ia, int ib, t_sinfo a, t_sinfo b)
{
	if (ia == 0)
		rotate_ib_to_top(ib, b);
	else if (ib == 0)
		rotate_ia_to_top(ia, a);
	else if (max(ia, ib) < max(a.len - ia, b.len - ib))
		rotate_iaib_up(ia, ib, a.stack, b.stack);
	else
		rotate_iaib_down(ia, ib, a, b);
}
