/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:10:52 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:56 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node **stack)
{
	t_node	*cur;
	int		len;

	cur = *stack;
	len = 0;
	while (cur->next)
	{
		len++;
		cur = cur->next;
	}
	len++;
	return (len);
}

t_node	*find_max(t_node **stack)
{
	int		max;
	t_node	*cur;
	t_node	*max_nbr;

	max = INT_MIN;
	cur = *stack;
	max_nbr = *stack;
	while (cur)
	{
		if (cur->nbr > max)
		{
			max = cur->nbr;
			max_nbr = cur;
		}
		cur = cur->next;
	}
	return (max_nbr);
}

t_node	*find_min(t_node **stack)
{
	int		min;
	t_node	*cur;
	t_node	*min_nbr;

	min = INT_MAX;
	cur = *stack;
	min_nbr = *stack;
	while (cur)
	{
		if (cur->nbr < min)
		{
			min = cur->nbr;
			min_nbr = cur;
		}
		cur = cur->next;
	}
	return (min_nbr);
}

void	index_init(t_node **stack, int len)
{
	int		i;
	int		min;
	t_node	*cur;
	t_node	*check;

	index_void(stack);
	i = 1;
	while (len > 0)
	{
		min = INT_MAX;
		cur = *stack;
		while (cur)
		{
			if (cur->nbr < min && cur->index == 0)
			{
				min = cur->nbr;
				check = cur;
			}
			cur = cur->next;
		}
		check->index = i;
		i++;
		len--;
	}
}

void	index_void(t_node **stack)
{
	t_node	*cur;

	cur = *stack;
	while (cur)
	{
		cur->index = 0;
		cur = cur->next;
	}
}
