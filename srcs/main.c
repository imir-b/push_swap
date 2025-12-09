/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/09 01:09:15 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_stack(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	printf("Stack a :\n");
	while (1)
	{
		printf("%i\n", stack_a->number);
		stack_a = stack_a->next;
		if (stack_a == tmp)
			break ;
	}
}

void	ft_algo_test(t_stack **a, t_stack **b)
{
	
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error(), 1);
	ft_algo_test(stack_a, stack_b); //ALGO ICI
	ft_put_stack(stack_a); //DEBUG
	ft_free_stack(&stack_a);
	return (0);
}
