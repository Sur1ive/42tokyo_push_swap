/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:07:15 by yxu               #+#    #+#             */
/*   Updated: 2024/01/30 17:36:21 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
		if (!str_is_int(argv[i++ + 1]))
			exit_with_msg(0, "Error\n");
	return (0);
}
