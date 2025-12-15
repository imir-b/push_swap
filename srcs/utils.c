/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:11:42 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/15 00:53:41 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	else
		return (0);
}

long int	ft_atol(char *nb)
{
	int			neg;
	long int	n;

	neg = 1;
	n = 0;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			neg = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		n = n * 10 + *nb - '0';
		if (n > 2147483648)
			break ;
		nb++;
	}
	return (neg * n);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (1)
	{
		if (tmp->number > tmp->next->number && tmp->next != stack)
			return (0);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (1);
}
