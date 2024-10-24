/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:07:18 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/17 17:42:46 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **s1, t_node **s2)
{
	t_node	*tmp;

	tmp = *s1;
	*s1 = tmp->next;
	tmp->next = *s2;
	*s2 = tmp;
}

void	pa(t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	push(a, b);
	ft_printf("pb\n");
}
