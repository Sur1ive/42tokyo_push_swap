/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:56 by yxu               #+#    #+#             */
/*   Updated: 2024/05/03 15:25:17 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	linknode(t_stack *node1, t_stack *node2)
{
	node1->next = node2;
	node2->prev = node1;
}

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	if ((*a)->next == *a)
		*a = NULL;
	else
	{
		linknode((*a)->prev, (*a)->next);
		*a = (*a)->next;
	}
	if (*b == NULL)
		linknode(tmp, tmp);
	else
	{
		linknode((*b)->prev, tmp);
		linknode(tmp, *b);
	}
	*b = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}