/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:32 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 11:08:21 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_smaller(int num, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (num > stackmax(b) || num < stackmin(b))
		return (stackmaxi(b));
	i = 1;
	if ((*b)->content < num && (*b)->prev->content > num)
		return (0);
	tmp = (*b)->next;
	while (tmp != *b)
	{
		if (tmp->content < num && tmp->prev->content > num)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	need_step(int ia, int ib, int alen, int blen)
{
	if (ia == 0)
		return (min(blen - ib, ib));
	if (ib == 0)
		return (min(alen - ia, ia));
	return (min(max(alen - ia, blen - ib), max(ia, ib)));
}

static void	rotate_for_push(t_sinfo a, t_sinfo b, int ia, int ib)
{
	t_stack	*tmp;
	int		min_step;
	int		step;
	int		min_step_ia;
	int		min_step_ib;

	min_step_ia = 0;
	min_step_ib = find_smaller((*a.stack)->content, b.stack);
	min_step = need_step(0, min_step_ib, a.len, b.len);
	tmp = (*a.stack)->next;
	ia = 1;
	while (tmp != *a.stack)
	{
		ib = find_smaller(tmp->content, b.stack);
		step = need_step(ia, ib, a.len, b.len);
		if (step < min_step)
		{
			min_step = step;
			min_step_ia = ia;
			min_step_ib = ib;
		}
		tmp = tmp->next;
		ia++;
	}
	rotate_iaib_to_top(min_step_ia, min_step_ib, a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		alen;
	int		blen;

	pb(2, a, b);
	alen = stacklen(a);
	blen = stacklen(b);
	while ((*a) != NULL)
	{
		rotate_for_push(genstackinfo(alen, a), genstackinfo(blen, b), 0, 0);
		pb(1, a, b);
		alen--;
		blen++;
	}
	rotate_ib_to_top(stackmaxi(b), genstackinfo(blen, b));
	while ((*b) != NULL)
		pa(1, a, b);
}
