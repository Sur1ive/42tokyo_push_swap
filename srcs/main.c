/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 14:41:15 by yxu              ###   ########.fr       */
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
		int_array[i] = ft_atoi(str_array[i]);
		i++;
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
		return (NULL);
	*len = str_array_len(str_array);
	i = 0;
	while (i < *len)
	{
		int_array[i] = ft_atoi(str_array[i]);
		i++;
	}
	doublefree(str_array);
	return (int_array);
}

int	main(int argc, char **argv)
{
	// t_arrs	arrs;
	// char	**str_arr;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
	// 	str_arr = ft_split(argv[1], ' ');
	// 	init_arrs(&arrs, str_arr, pplen(str_arr));
	// 	arrs.str_arr_malloced = 1;
	}
	// else
	// 	init_arrs(&arrs, argv + 1, argc - 1);
	// if (arrs.arr == NULL || arrs.str_arr == NULL)
	// 	free_exit(&arrs, "Error\n");
	// strarr_to_arr(&arrs);
	// if (!check_duplicate(arrs.arr, arrs.len))
	// 	free_exit(&arrs, "Error\n");
	// bubble_sort(arrs.arr, arrs.len);
	// free_exit(&arrs, NULL);
}
