/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:17 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 14:37:56 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	str_array_len(char **str_array)
{
	int	len;

	if (str_array == NULL)
		return (0);
	len = 0;
	while (*str_array++)
		len++;
	return (len);
}

int	doublefree(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return (0);
	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (0);
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
