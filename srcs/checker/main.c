/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:26:17 by yxu               #+#    #+#             */
/*   Updated: 2024/05/06 18:02:25 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_error_handler(int errorcode, t_stack **a, t_stack **b)
{
	stackclear(a);
	stackclear(b);
	error_handler(errorcode);
}

static void	finalcheck(t_stack **a, t_stack **b)
{
	if (*b == NULL && stack_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stackclear(a);
	stackclear(b);
	exit(0);
}

static void	parse_cmd_sub(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strcmp(cmd, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(cmd, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (ft_strcmp(cmd, "\n") == 0)
	{
		free(cmd);
		finalcheck(a, b);
	}
	else
	{
		free(cmd);
		checker_error_handler(NO_SUCH_CMD, a, b);
	}
}

static void	parse_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (cmd == NULL)
		checker_error_handler(READ_FAIL, a, b);
	else if (ft_strcmp(cmd, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(cmd, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(cmd, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rotate(b);
	else
		parse_cmd_sub(cmd, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	a = parse(argc, argv);
	b = NULL;
	while (1)
	{
		cmd = get_next_line(0);
		parse_cmd(cmd, &a, &b);
		free(cmd);
	}
	return (0);
}
