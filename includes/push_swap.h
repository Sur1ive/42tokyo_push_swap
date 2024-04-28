/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/04/28 22:05:26 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# ifndef MAX_SUPPORTED_ELEMENTS_NUM
#  define MAX_SUPPORTED_ELEMENTS_NUM 1000
# endif

# define MALLOC_ERROR 0
# define NUM_OF_ARGUMENTS_ERROR 1
# define FORMAT_OF_ARGUMENTS_ERROR 2
# define DUPLICATES_IN_ARGUMENTS 3
# define TOO_MUCH_ELEMENTS 4

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	str_array_to_int_array(int *int_array, int *len, char **str_array);
void	str_to_int_array(int *int_array, int *len, char *str);
int		str_is_int(char *s);
int		check_duplicate(int *arr, int len);
void	error_handler(int error_num);
t_stack	**int_array_to_stack(int *int_array, int len);
void	stackclear(t_stack **stack);

#endif
