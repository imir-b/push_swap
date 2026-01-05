/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/05 02:20:34 by vbleskin         ###   ########.fr       */
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
		return (ERROR);
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error());
	if (ft_is_sorted(stack_a))
		return (SUCCESS);
	ft_push_swap(&stack_a, &stack_b, PRINT_Y);
	ft_free_stack(&stack_a);
	return (SUCCESS);
}
