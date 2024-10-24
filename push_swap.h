/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:41:01 by irkalini          #+#    #+#             */
/*   Updated: 2024/10/24 18:05:51 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}	t_node;

char	**split(char *s, char c);

void	free_err(t_node **a, t_node **b);
void	free_stack(t_node **stack);
void	free_tab(char **tab);
int		err_dub(t_node *a, int n);
int		err_syn(char *s);
int		only_space(char *s);
void	swap(t_node **stack);
t_node	*stack_init(t_node **a, t_node **b, char **argv);
void	append_node(t_node **stack, int n);
int		stack_sorted(t_node **stack);
int		stack_len(t_node **stack);
t_node	*find_max(t_node **stack);
t_node	*find_min(t_node **stack);
void	sort_stack(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_more(t_node **a, t_node **b);
void	index_init(t_node **stack, int len);
void	index_void(t_node **stack);
void	sort_next(t_node **a, t_node **b);
int		first_half_check(t_node **b, int nbr, int half);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
