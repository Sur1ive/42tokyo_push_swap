/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3or5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:36:50 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 10:53:18 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_ia_to_bot(int i, t_sinfo a)
{
	if (a.len - 1 - i > i + 1)
		ra(i + 1, a.stack);
	else
		rra(a.len - 1 - i, a.stack);
}

static void	push_swap3(t_stack **a)
{
	if (stack_sorted(a) == 1)
		return ;
	rotate_ia_to_bot(stackmaxi(a), genstackinfo(3, a));
	if (stack_sorted(a) != 1)
		sa(a);
}

void	push_swap5(t_stack **a, t_stack **b)
{
	int		alen;

	alen = stacklen(a);
	if (alen <= 3)
		push_swap3(a);
	else if (alen <= 5)
	{
		rotate_ia_to_top(stackmini(a), genstackinfo(alen, a));
		pb(1, a, b);
		rotate_ia_to_top(stackmini(a), genstackinfo(alen - 1, a));
		pb(1, a, b);
		push_swap3(a);
		pa(2, a, b);
	}
}
