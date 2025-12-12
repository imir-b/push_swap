/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:05:46 by vlad              #+#    #+#             */
/*   Updated: 2025/12/12 17:58:47 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	ft_exec(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))      sa(a, 0);
    else if (!ft_strcmp(line, "sb\n")) sb(b, 0);
    else if (!ft_strcmp(line, "ss\n")) ss(a, b, 0);
    else if (!ft_strcmp(line, "pa\n")) pa(a, b, 0);
    else if (!ft_strcmp(line, "pb\n")) pb(b, a, 0);
    else if (!ft_strcmp(line, "ra\n")) ra(a, 0);
    else if (!ft_strcmp(line, "rb\n")) rb(b, 0);
    else if (!ft_strcmp(line, "rr\n")) rr(a, b, 0);
    else if (!ft_strcmp(line, "rra\n")) rra(a, 0);
    else if (!ft_strcmp(line, "rrb\n")) rrb(b, 0);
    else if (!ft_strcmp(line, "rrr\n")) rrr(a, b, 0);
    else
    {
        ft_free_stack(a);
        ft_free_stack(b);
        free(line);
        ft_error();
        exit(1);
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
		return (1);
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error(), 1);
	line = get_next_line(0);
	while (line)
	{
		ft_exec(line, &stack_a, &stack_b);
		free (line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 0);
}
