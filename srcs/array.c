/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:55:56 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 16:57:10 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	str_array_len(char **str_array)
{
	int	len;

	if (str_array == NULL)
		return (0);
	len = 0;
	while (*str_array++)
		len++;
	return (len);
}

static int	doublefree(char **str_array)
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

void	str_array_to_int_array(int *int_array, int *len, char **str_array)
{
	int	i;

	*len = str_array_len(str_array);
	if (*len > MAX_SUPPORTED_ELEMENTS_NUM)
		error_handler(TOO_MUCH_ELEMENTS);
	i = 0;
	while (i < *len)
	{
		if (str_is_int(str_array[i]))
			int_array[i] = ft_atoi(str_array[i]);
		else
			error_handler(FORMAT_OF_ARGUMENTS_ERROR);
		i++;
	}
}

void	str_to_int_array(int *int_array, int *len, char *str)
{
	char	**str_array;
	int		i;

	str_array = ft_split(str, ' ');
	if (str_array == NULL)
		error_handler(MALLOC_ERROR);
	*len = str_array_len(str_array);
	if (*len > MAX_SUPPORTED_ELEMENTS_NUM)
		error_handler(TOO_MUCH_ELEMENTS);
	i = 0;
	while (i < *len)
	{
		if (str_is_int(str_array[i]))
			int_array[i] = ft_atoi(str_array[i]);
		else
		{
			doublefree(str_array);
			error_handler(FORMAT_OF_ARGUMENTS_ERROR);
		}
		i++;
	}
	doublefree(str_array);
}
