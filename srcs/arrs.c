/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:59:51 by yxu               #+#    #+#             */
/*   Updated: 2024/01/30 21:02:47 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_arrs(t_arrs *arrs, char **str_arr, int len)
{
	arrs->str_arr_malloced = 0;
	arrs->str_arr = str_arr;
	arrs->len = len;
	arrs->arr = (int *)malloc(sizeof(int) * arrs->len);
}

void	strarr_to_arr(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (arrs->str_arr[i])
	{
		if (str_is_int(arrs->str_arr[i]))
			arrs->arr[i] = ft_atoi(arrs->str_arr[i]);
		else
			free_exit(arrs, "Error\n");
		i++;
	}
}

void	free_exit(t_arrs *arrs, char *msg)
{
	if (arrs->str_arr_malloced)
		free_pp(arrs->str_arr);
	free(arrs->arr);
	if (msg == NULL)
		exit(0);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(0);
}

int	check_duplicate(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
			if (arr[i] == arr[j++])
				return (0);
		i++;
	}
	return (1);
}
