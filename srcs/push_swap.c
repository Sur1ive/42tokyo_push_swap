/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:32 by yxu               #+#    #+#             */
/*   Updated: 2024/05/05 23:49:56 by yxu              ###   ########.fr       */
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

static void	rotate_to_next(int alen, int blen, t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min_step;
	int		step;
	int		ia;
	int		ib;
	int		min_step_ia;
	int		min_step_ib;

	min_step_ia = 0;
	min_step_ib = find_smaller((*a)->content, b);
	min_step = need_step(0, min_step_ib, alen, blen);
	tmp = (*a)->next;
	ia = 1;
	while (tmp != *a)
	{
		ib = find_smaller(tmp->content, b);
		step = need_step(ia, ib, alen, blen);
		if (step < min_step)
		{
			min_step = step;
			min_step_ia = ia;
			min_step_ib = ib;
		}
		tmp = tmp->next;
		ia++;
	}
	rotate_iaib_to_top(min_step_ia, min_step_ib, genstackinfo(alen, a), genstackinfo(blen, b));
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		alen;
	int		blen;

	pb(2, a, b);
	while ((*a) != NULL)
	{
		alen = stacklen(a);
		blen = stacklen(b);
		rotate_to_next(alen, blen, a, b);
		pb(1, a, b);
	}
	rotate_ib_to_top(stackmaxi(b), b);
	while ((*b) != NULL)
		pa(1, a, b);
}
