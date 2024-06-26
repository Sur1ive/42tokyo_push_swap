/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:58 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 18:37:31 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# ifndef MAX_SUPPORTED_ELEMENTS_NUM
#  define MAX_SUPPORTED_ELEMENTS_NUM 2000
# endif

# define MALLOC_ERROR 1
# define NUM_OF_ARGUMENTS_ERROR 2
# define FORMAT_OF_ARGUMENTS_ERROR 3
# define DUPLICATES_IN_ARGUMENTS 4
# define TOO_MUCH_ELEMENTS 5
# define NO_SUCH_CMD 6

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

t_stack	*parse(int argc, char **argv);
int		check_duplicate(int *arr, int len);
void	error_handler(int error_num);
int		str_is_int(char *s);
void	str_array_to_int_array(int *int_array, int *len, char **str_array);
void	str_to_int_array(int *int_array, int *len, char *str);
t_stack	*int_array_to_stack(int *int_array, int len);
void	stackclear(t_stack **stack);
int		stacklen(t_stack **a);
void	printstack(t_stack **a);
int		stackmaxi(t_stack **a);
int		stackmini(t_stack **a);
int		stackmax(t_stack **a);
int		stackmin(t_stack **a);
int		stack_sorted(t_stack **a);
t_sinfo	genstackinfo(int len, t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a);
void	rotate(t_stack **a);
void	swap(t_stack **a);
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
void	rotate_ia_to_top(int i, t_sinfo a);
void	rotate_ib_to_top(int i, t_sinfo b);
void	rotate_iaib_to_top(int ia, int ib, t_sinfo a, t_sinfo b);
void	push_swap(t_stack **a, t_stack **b);
void	push_swap5(t_stack **a, t_stack **b);

#endif
