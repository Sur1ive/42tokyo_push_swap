/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:32 by yxu               #+#    #+#             */
/*   Updated: 2024/05/03 21:56:02 by yxu              ###   ########.fr       */
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
	t_stack	*top;
	t_stack	*tmp;
	int		len;

	if (*a == NULL)
		return (0);
	len = 1;
	top = *a;
	tmp = (*a)->next;
	while (tmp != top)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

static void	rotate_i_to_top(int i, t_stack **b)
{
	int	len;

	len = stacklen(b);
	if (len - i > i)
	{
		while (i-- > 0)
			rb(b);
	}
	else
	{
		while (len - i++ > 0)
			rrb(b);
	}
}

static int	findstackmax(t_stack **a)
{
	t_stack	*top;
	t_stack	*tmp;
	int		max;
	int		max_i;
	int		i;

	if (*a == NULL)
		return (0);
	top = *a;
	tmp = (*a)->next;
	max_i = 0;
	max = (*a)->content;
	i = 1;
	while (tmp != top)
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
	t_stack	*top;
	t_stack	*tmp;
	int		min;
	int		min_i;
	int		i;

	if (*a == NULL)
		return (0);
	top = *a;
	tmp = (*a)->next;
	min_i = 0;
	min = (*a)->content;
	i = 1;
	while (tmp != top)
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
	t_stack	*top;
	t_stack	*tmp;
	int		i;

	if (num > get_i_content(findstackmax(b), b)
		|| num < get_i_content(findstackmin(b), b))
		return (findstackmax(b));
	i = 1;
	top = *b;
	if (top->content < num && top->prev->content > num)
		return (0);
	tmp = (*b)->next;
	while (tmp != top)
	{
		if (tmp->content < num && tmp->prev->content > num)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	rotate_to_next(t_stack **a, t_stack **b)
{
	rotate_i_to_top(find_smaller((*a)->content, b), b);
	// t_stack	*top;
	// t_stack	*tmp;
	// int		min_step;
	// int		step;

	// min_step = INT_MIN;
	// top = *a;
	// tmp = (*a)->next;
	// while (tmp != top)
	// {
	// 	step = need_step(a, b);
	// 	if (step < min_step)
	// 	tmp = tmp->next;

	// }
}

void	printstack(t_stack **a)
{
	t_stack	*top;
	t_stack	*tmp;

	if (*a == NULL)
	{
		ft_printf("------\n(empty stack)\n------\n");
		return ;
	}
	top = *a;
	ft_printf("------\nstack:\n%d\n", top->content);
	tmp = (*a)->next;
	while (tmp != top)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("------\n");
}

void	push_swap(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	while ((*a) != NULL)
	{
		rotate_to_next(a, b);
		pb(a, b);
	}
	rotate_i_to_top(findstackmax(b), b);
	while ((*b) != NULL)
		pa(a, b);
}
