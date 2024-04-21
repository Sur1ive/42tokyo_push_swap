/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:59:51 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 15:15:52 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(int error_num)
{
	char	*msg;

	// if (error_num == MALLOC_ERROR)
	// 	msg = "Malloc error\n";
	// if (error_num == NUM_OF_ARGUMENTS_ERROR)
	// 	msg = "Wrong number of arguments\n";
	// if (error_num == FORMAT_OF_ARGUMENTS_ERROR)
	// 	msg = "Wrong format of arguments\n";
	msg = "Error\n";
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
