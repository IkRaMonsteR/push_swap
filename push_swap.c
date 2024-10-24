/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:33:35 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/24 18:10:31 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	tab = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]) || only_space(argv[1]))
		return (write(2, "Error\n", 6));
	else if (argc == 2)
	{
		tab = split(argv[1], ' ');
		if (tab == NULL || stack_init(&a, &b, tab) == NULL)
			return (free_tab(tab), 0);
		free_tab(tab);
	}
	else
	{
		if (stack_init(&a, &b, argv + 1) == NULL)
			return (0);
	}
	if (!stack_sorted(&a))
		sort_stack(&a, &b);
	free_stack(&a);
}
