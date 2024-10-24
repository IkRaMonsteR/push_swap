/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:08:39 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/24 17:27:37 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err_syn(char *s)
{
	if (!(*s == '-' || *s == '+' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '-' || *s == '+') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

int	err_dub(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*c;
	t_node	*n;

	c = *stack;
	while (c != NULL)
	{
		n = c;
		c = c->next;
		free(n);
	}
	*stack = NULL;
}

void	free_err(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
}

int	only_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (1);
	return (0);
}
