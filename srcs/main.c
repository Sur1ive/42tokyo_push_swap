/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/01/31 22:11:53 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  need                            */
/*  sort 100num with <700steps      */
/*  sort 500num with <5500steps     */

// static void	repeat(char *msg, int count)
// {
// 	while (count-- > 0)
// 		ft_printf("%s", msg);
// }

static void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;
	// int	count;

	i = 0;
	while (i < len)
	{
		j = 0;
		// count = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				// repeat("ra\n", count);
				ft_printf("sa\n");
			}
			ft_printf("ra\n");
			// count++;
			j++;
		}
		ft_printf("ra\n");
		i++;
	}
	// repeat("ra\n", count);
}

int	main(int argc, char **argv)
{
	t_arrs	arrs;
	char	**str_arr;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str_arr = ft_split(argv[1], ' ');
		init_arrs(&arrs, str_arr, pplen(str_arr));
		arrs.str_arr_malloced = 1;
	}
	else
		init_arrs(&arrs, argv + 1, argc - 1);
	if (arrs.arr == NULL || arrs.str_arr == NULL)
		free_exit(&arrs, "Error\n");
	strarr_to_arr(&arrs);
	if (!check_duplicate(arrs.arr, arrs.len))
		free_exit(&arrs, "Error\n");
	bubble_sort(arrs.arr, arrs.len);
	free_exit(&arrs, NULL);
}
