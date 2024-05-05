/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:12:39 by yxu               #+#    #+#             */
/*   Updated: 2024/05/05 23:51:26 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	stackmaxi(t_stack **a)
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

int	stackmax(t_stack **a)
{
	t_stack	*tmp;
	int		max;
	int		i;

	if (*a == NULL)
		return (0);
	tmp = (*a)->next;
	max = (*a)->content;
	i = 1;
	while (tmp != *a)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}

int	stackmin(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	if (*a == NULL)
		return (0);
	tmp = (*a)->next;
	min = (*a)->content;
	i = 1;
	while (tmp != *a)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

t_sinfo	genstackinfo(int len, t_stack **stack)
{
	t_sinfo	stackinfo;

	stackinfo.len = len;
	stackinfo.stack = stack;
	return (stackinfo);
}
