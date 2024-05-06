/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 15:35:15 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <libc.h>

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parse(argc, argv);
	b = NULL;
	if (stacklen(&a) <= 5)
		push_swap5(&a, &b);
	else
		push_swap(&a, &b);
	stackclear(&a);
	return (0);
}
