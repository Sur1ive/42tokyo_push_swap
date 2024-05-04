/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:59:51 by yxu               #+#    #+#             */
/*   Updated: 2024/05/03 23:18:20 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(int error_num)
{
	char	*msg;

	(void)error_num;
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

int	check_sorted(int *arr, int len)
{
	int	i;

	if (len == 1)
		return (1);
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (num * sign);
}

int	str_is_int(char *s)
{
	int		i;
	int		len;
	long	num;

	len = ft_strlen(s);
	if (len > 11 || (len > 1 && s[0] == '0'))
		return (0);
	if (s[0] != '-' && s[0] != '+' && (s[0] < '0' || s[0] > '9'))
		return (0);
	if ((s[0] == '-' || s[0] == '+') && (len == 1 || (len > 2 && s[1] == '0')))
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
