/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:32 by yxu               #+#    #+#             */
/*   Updated: 2024/05/04 18:46:31 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_i_content(int i, t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (i-- > 0)
		tmp = tmp->next;
	return (tmp->content);
}

int	stacklen(t_stack **a)
{
	t_stack	*tmp;
	int		len;

	if (*a == NULL)
		return (0);
	len = 1;
	tmp = (*a)->next;
	while (tmp != *a)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

static void	rotate_ia_to_top(int i, t_stack **a)
{
	int	len;

	len = stacklen(a);
	if (len - i > i)
		ra(i, a);
	else
		rra(len - i, a);
}

static void	rotate_ib_to_top(int i, t_stack **b)
{
	int	len;

	len = stacklen(b);
	if (len - i > i)
		rb(i, b);
	else
		rrb(len - i, b);
}

static int	findstackmax(t_stack **a)
{
	t_stack	*tmp;
	int		max;
	int		max_i;
	int		i;

	if (*a == NULL)
		return (0);
	tmp = (*a)->next;
	max_i = 0;
	max = (*a)->content;
	i = 1;
	while (tmp != *a)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			max_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_i);
}

static int	findstackmin(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		min_i;
	int		i;

	if (*a == NULL)
		return (0);
	tmp = (*a)->next;
	min_i = 0;
	min = (*a)->content;
	i = 1;
	while (tmp != *a)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			min_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_i);
}

static int	find_smaller(int num, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (num > get_i_content(findstackmax(b), b)
		|| num < get_i_content(findstackmin(b), b))
		return (findstackmax(b));
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

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

static void	rotate_iaib_to_top(int ia, int ib, int alen, int blen, t_stack **a, t_stack **b)
{
	if (ia == 0)
		rotate_ib_to_top(ib, b);
	else if (ib == 0)
		rotate_ia_to_top(ia, a);
	else if (max(ia, ib) < max(alen - ia, blen - ib))
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
	else
	{
		if (alen - ia < blen - ib)
		{
			rrr(alen - ia, a, b);
			rrb(blen - ib - alen + ia, b);
		}
		else
		{
			rrr(blen - ib, a, b);
			rra(alen - ia - blen + ib, a);
		}
	}
}

static int	need_step(int ia, int ib, int alen, int blen)
{
	if (ia == 0)
		return (min(blen - ib, ib));
	if (ib == 0)
		return (min(alen - ia, ia));
	return (min(max(alen - ia, blen - ib), max(ia, ib)));
}

static void	rotate_to_next(t_stack **a, t_stack **b)
{
	// rotate_i_to_top(find_smaller((*a)->content, b), b);
	t_stack	*tmp;
	int		min_step;
	int		step;
	int		alen;
	int		blen;
	int		ia;
	int		ib;
	int		min_step_ia;
	int		min_step_ib;

	alen = stacklen(a);
	blen = stacklen(b);
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
	rotate_iaib_to_top(min_step_ia, min_step_ib, alen, blen, a, b);
	printstack(a);
	printstack(b);
}

void	printstack(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
	{
		ft_printf("------\n(empty stack)\n------\n");
		return ;
	}
	ft_printf("------\nstack:\n%d\n", (*a)->content);
	tmp = (*a)->next;
	while (tmp != *a)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("------\n");
}

void	push_swap(t_stack **a, t_stack **b)
{
	pb(2, a, b);
	while ((*a) != NULL)
	{
		rotate_to_next(a, b);
		pb(1, a, b);
	}
	rotate_ib_to_top(findstackmax(b), b);
	while ((*b) != NULL)
		pa(1, a, b);
}
