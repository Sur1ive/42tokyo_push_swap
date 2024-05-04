/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/05/04 13:46:20 by yxu              ###   ########.fr       */
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

typedef struct s_ops
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

}	t_ops;

void	str_array_to_int_array(int *int_array, int *len, char **str_array);
void	str_to_int_array(int *int_array, int *len, char *str);
int		str_is_int(char *s);
int		check_duplicate(int *arr, int len);
int		check_sorted(int *arr, int len);
void	error_handler(int error_num);
t_stack	*int_array_to_stack(int *int_array, int len);
void	stackclear(t_stack **stack);
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
void	push_swap(t_stack **a, t_stack **b);
void	printstack(t_stack **a);

#endif
