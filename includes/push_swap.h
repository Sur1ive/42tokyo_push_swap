/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/05/05 23:51:11 by yxu              ###   ########.fr       */
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

typedef struct s_sinfo
{
	int				len;
	struct s_stack	**stack;
}	t_sinfo;

int		check_duplicate(int *arr, int len);
int		check_sorted(int *arr, int len);
void	error_handler(int error_num);
int		str_is_int(char *s);
void	str_array_to_int_array(int *int_array, int *len, char **str_array);
void	str_to_int_array(int *int_array, int *len, char *str);
t_stack	*int_array_to_stack(int *int_array, int len);
void	stackclear(t_stack **stack);
int		stacklen(t_stack **a);
void	printstack(t_stack **a);
int		stackmaxi(t_stack **a);
int		stackmax(t_stack **a);
int		stackmin(t_stack **a);
t_sinfo	genstackinfo(int len, t_stack **stack);
void	pa(int n, t_stack **a, t_stack **b);
void	pb(int n, t_stack **a, t_stack **b);
void	rra(int n, t_stack **a);
void	rrb(int n, t_stack **b);
void	rrr(int n, t_stack **a, t_stack **b);
void	ra(int n, t_stack **a);
void	rb(int n, t_stack **b);
void	rr(int n, t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		max(int a, int b);
int		min(int a, int b);
void	rotate_ia_to_top(int i, t_stack **a);
void	rotate_ib_to_top(int i, t_stack **b);
void	rotate_iaib_to_top(int ia, int ib, t_sinfo a, t_sinfo b);
void	push_swap(t_stack **a, t_stack **b);

#endif
