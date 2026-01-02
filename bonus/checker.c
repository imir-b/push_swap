/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:05:46 by vlad              #+#    #+#             */
/*   Updated: 2026/01/02 06:55:01 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_line_cmp(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, PRINT_N);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, PRINT_N);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, PRINT_N);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, PRINT_N);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, PRINT_N);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, PRINT_N);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, PRINT_N);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, PRINT_N);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, PRINT_N);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, PRINT_N);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, PRINT_N);
	else
		return (ERROR);
	return (SUCCESS);
}

void	ft_exec(char *line, t_stack **a, t_stack **b)
{
	if (ft_line_cmp(line, a, b))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		free(line);
		ft_error("wtf checker died");
		exit(ERROR);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (ft_error("checker needs more than 2 args"));
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error("init stack a checker"));
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_exec(line, &stack_a, &stack_b);
		free (line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), SUCCESS);
}
