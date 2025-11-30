/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:50:22 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/30 03:54:00 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*end;

	end = (*stack)->prev;
	while (*stack != end)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
	free(*stack);
}

void	ft_free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

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

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
		return (1);
	if (ft_init_stack(&stack_a, ac, av))
		return (ft_error(), 1);

	//algo

	ft_put_stack(stack_a);
	ft_free_stack(&stack_a);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	char	**args;

// 	if (ac < 2)
// 		return (ft_error(), 1);
// 	if (ac == 2)
// 		args = ft_split((const char *)av[1], ' ');
// 	else
// 		args = av + 1;
// 	if (!ft_parsing(&stack_a, args))
// 	{
// 		ft_free_stack(&stack_a);
// 		if (ac == 2)
// 			ft_free_split(args);
// 		return (ft_error(), 1);
// 	}
// 	//algo
// 	ft_free_stack(&stack_a);
// 	if (ac == 2)
// 		ft_free_split(args);
// 	return (0);
// }
