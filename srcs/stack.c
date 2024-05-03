/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:23:45 by yxu               #+#    #+#             */
/*   Updated: 2024/05/03 10:06:01 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stacknew(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*p;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack)
	{
		p = *stack;
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
	else
		*stack = new;
}

void	stackclear(t_stack **stack)
{
	t_stack	*p;
	t_stack	*top;

	if (stack == NULL)
		return ;
	top = *stack;
	while (*stack)
	{
		p = (*stack)->next;
		free(*stack);
		if (p == top)
			break ;
		*stack = p;
	}
}

t_stack	*int_array_to_stack(int *int_array, int len)
{
	int		i;
	t_stack	*p;
	t_stack	*top;

	p = stacknew(int_array[0]);
	if (p == NULL)
		error_handler(MALLOC_ERROR);
	top = p;
	i = 1;
	while (i < len)
	{
		p = stacknew(int_array[i]);
		if (p == NULL)
		{
			stackclear(&top);
			error_handler(MALLOC_ERROR);
		}
		stackadd_back(&top, p);
		i++;
	}
	p->next = top;
	top->prev = p;
	return (top);
}
