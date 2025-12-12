/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/12 16:28:25 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void	ft_put_stack(t_stack *stack, char c)
// {
// 	t_stack	*tmp;

// 	if (!stack)
// 	{
// 		printf("-> Stack %c is empty\n", c);
// 		return ;
// 	}
// 	tmp = stack;
// 	printf("--- Stack %c ---\n", c);
// 	while (1)
// 	{
// 		printf("%i\n", stack->number);
// 		stack = stack->next;
// 		if (stack == tmp)
// 			break ;
// 	}
// }

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
	ft_push_swap(&stack_a, &stack_b, 1);
	ft_free_stack(&stack_a);
	return (0);
}
