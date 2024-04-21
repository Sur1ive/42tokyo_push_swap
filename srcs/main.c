/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 15:18:43 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  need                            */
/*  sort 100num with <700steps      */
/*  sort 500num with <5500steps     */

int	*str_array_to_int_array(int *len, char **str_array)
{
	int	int_array[MAX_SUPPORTED_ELEMENTS_NUM];
	int	i;

	*len = str_array_len(str_array);
	i = 0;
	while (i < *len)
	{
		if (str_is_int(int_array[i]))
			int_array[i] = ft_atoi(str_array[i]);
		else
			error_handler(FORMAT_OF_ARGUMENTS_ERROR);
	}
	return (int_array);
}

int	*str_to_int_array(int *len, char *str)
{
	int		int_array[MAX_SUPPORTED_ELEMENTS_NUM];
	char	**str_array;
	int		i;

	str_array = ft_split(str, ' ');
	if (str_array == NULL)
		error_handler(MALLOC_ERROR);
	*len = str_array_len(str_array);
	i = 0;
	while (i < *len)
	{
		if (str_is_int(int_array[i]))
			int_array[i] = ft_atoi(str_array[i]);
		else
		{
			doublefree(str_array);
			error_handler(FORMAT_OF_ARGUMENTS_ERROR);
		}
		i++;
	}
	doublefree(str_array);
	return (int_array);
}

#include <libc.h>
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv)
{
	int	len;
	int	*int_array;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		int_array = str_to_int_array(&len, argv[1]);
	else
		int_array = str_array_to_int_array(&len, &argv[1]);
	if (!check_duplicate(int_array, len))
		error_handler(DUPLICATES_IN_ARGUMENTS);

	return (0);
}
