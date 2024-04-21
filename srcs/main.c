/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 17:16:30 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  need                            */
/*  sort 100num with <700steps      */
/*  sort 500num with <5500steps     */

void	renumber(int *int_array)
{

}

t_stack	int_array_to_stack(int *int_array)
{

}

#include <libc.h>
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	int		len;
	int		int_array[MAX_SUPPORTED_ELEMENTS_NUM];
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		str_to_int_array(int_array, &len, argv[1]);
	else
		str_array_to_int_array(int_array, &len, &argv[1]);
	if (!check_duplicate(int_array, len))
		error_handler(DUPLICATES_IN_ARGUMENTS);
	renumber(int_array);
	a = int_array_to_stack(int_array);
	return (0);
}
