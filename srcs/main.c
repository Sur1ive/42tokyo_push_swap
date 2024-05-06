/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 11:31:21 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  need                            */
/*  sort 100num with <700steps      */
/*  sort 500num with <5500steps     */

// #include <libc.h>
// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	int		len;
	int		int_array[MAX_SUPPORTED_ELEMENTS_NUM];
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		str_to_int_array(int_array, &len, argv[1]);
	else
		str_array_to_int_array(int_array, &len, &argv[1]);
	if (len == 0)
		error_handler(FORMAT_OF_ARGUMENTS_ERROR);
	if (!check_duplicate(int_array, len))
		error_handler(DUPLICATES_IN_ARGUMENTS);
	if (check_sorted(int_array, len))
		return (0);
	a = int_array_to_stack(int_array, len);
	b = NULL;
	if (len <= 5)
		push_swap5(&a, &b);
	else
		push_swap(&a, &b);
	stackclear(&a);
	return (0);
}
