/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:11:42 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/02 05:43:12 by vbleskin         ###   ########.fr       */
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

/**
 * Fonction qui convertit un char * 'nb' en long int.
 */
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

/**
 * Fonction qui verifie si la 'stack' est bien triee.
 */
int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (TRUE);
	tmp = stack;
	while (TRUE)
	{
		if (tmp->number > tmp->next->number && tmp->next != stack)
			return (FALSE);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (TRUE);
}
