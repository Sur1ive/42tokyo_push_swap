/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 11:39:42 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

# ifndef MAX_SUPPORTED_ELEMENTS_NUM
#  define MAX_SUPPORTED_ELEMENTS_NUM 2000
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

typedef struct s_sinfo
{
	int				len;
	struct s_stack	**stack;
}	t_sinfo;

#endif
