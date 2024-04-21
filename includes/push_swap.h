/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/04/21 14:37:04 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# ifndef MAX_SUPPORTED_ELEMENTS_NUM
#  define MAX_SUPPORTED_ELEMENTS_NUM 1000
# endif

typedef struct s_arrs{
	int		len;
	int		str_arr_malloced;
	char	**str_arr;
	int		*arr;
}	t_arrs;

void	free_exit(t_arrs *arrs, char *msg);
int		str_is_int(char *s);
int		check_duplicate(int *arr, int len);
void	init_arrs(t_arrs *arrs, char **str_arr, int len);
void	strarr_to_arr(t_arrs *arrs);
int		doublefree(char **str_array);
int		str_array_len(char **str_array);

#endif
