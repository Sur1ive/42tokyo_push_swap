/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/01/30 21:03:43 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
int		free_pp(char **pp);
int		pplen(char **pp);

#endif
