/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:26:17 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 15:42:47 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 2)
		error_handler(FORMAT_OF_ARGUMENTS_ERROR);
	a = parse(argc, **argv);
	b = NULL;
	ft_printf("%s", get_next_line(0));
	stackclear(&a);
	stackclear(&b);
	return (0);
}
