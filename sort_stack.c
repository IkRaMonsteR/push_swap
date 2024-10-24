/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:07:09 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/22 20:37:09 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	if (stack_len(a) == 2)
		sa(a);
	else if (stack_len(a) == 3)
		sort_three(a);
	else if (stack_len(a) == 4)
		sort_four(a, b);
	else if (stack_len(a) == 5)
		sort_five(a, b);
	else
		sort_more(a, b);
}

void	sort_three(t_node **a)
{
	t_node	*max;

	max = find_max(a);
	if ((*a)->nbr == max->nbr)
		ra(a);
	else if ((*a)->next->nbr == max->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min;

	min = find_min(a);
	if ((*a)->nbr == min->nbr)
		pb(a, b);
	else if ((*a)->next->nbr == min->nbr)
	{
		ra(a);
		pb(a, b);
	}
	else
	{
		while ((*a)->nbr != min->nbr)
			rra(a);
		pb(a, b);
	}
	if (!stack_sorted(a))
		sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min;

	min = find_min(a);
	if ((*a)->nbr == min->nbr)
		pb(a, b);
	else if ((*a)->next->nbr == min->nbr)
	{
		ra(a);
		pb(a, b);
	}
	else
	{
		while ((*a)->nbr != min->nbr)
			rra(a);
		pb(a, b);
	}
	if (!stack_sorted(a))
		sort_four(a, b);
	pa(a, b);
}
