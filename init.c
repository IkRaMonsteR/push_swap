/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:26:46 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/24 18:05:26 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = node;
	}
}

t_node	*stack_init(t_node **a, t_node **b, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (err_syn(argv[i]))
			return (free_err(a, b), NULL);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_err(a, b), NULL);
		if (err_dub(*a, (int)n))
			return (free_err(a, b), NULL);
		append_node(a, (int)n);
		i++;
	}
	return (*a);
}

int	stack_sorted(t_node **stack)
{
	t_node	*cur;

	cur = *stack;
	while (cur->next)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
