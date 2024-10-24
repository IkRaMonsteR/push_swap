/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:29:47 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/23 16:23:06 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_node **a, t_node **b)
{
	int	start;
	int	end;

	start = 0;
	end = 15;
	index_init(a, stack_len(a));
	while (*a)
	{
		if ((*a)->index <= start)
		{
			pb(a, b);
			rb(b);
			start++;
			end++;
		}
		else if ((*a)->index > start && (*a)->index < end)
		{
			pb(a, b);
			start++;
			end++;
		}
		else if ((*a)->index >= end)
			ra(a);
	}
	sort_next(a, b);
}

void	sort_next(t_node **a, t_node **b)
{
	int		half;
	t_node	*check;

	check = NULL;
	while (*b)
	{
		check = find_max(b);
		half = first_half_check(b, check->nbr, (stack_len(b) / 2));
		while ((*b)->nbr != check->nbr)
		{
			if (half == 1)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

int	first_half_check(t_node **b, int nbr, int half)
{
	t_node	*cur;

	cur = *b;
	while (half > 0 && cur)
	{
		if (cur->nbr == nbr)
			return (1);
		cur = cur->next;
		half--;
	}
	return (0);
}
