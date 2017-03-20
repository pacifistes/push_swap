/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:04:20 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/09 17:12:09 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	other_command1(t_list **stack_a, t_point *p, int n)
{
	p->tmp = *stack_a;
	if ((p->tmp->value < p->tmp->next->value && !p->tmp->next->next) ||
	(p->tmp->value > p->tmp->next->value && p->tmp->next->next
	&& p->tmp->value > p->tmp->next->next->value && p->tmp->next->value <
	p->tmp->next->next->value))
		do_sa_sb(stack_a, p, n);
	else if (!p->tmp->next->next)
		return ;
	else if (p->tmp->value > p->tmp->next->value &&
	p->tmp->value < p->tmp->next->next->value)
		do_ra_rb(stack_a, p, n);
	else if (p->tmp->value < p->tmp->next->value && T)
	{
		do_ra_rb(stack_a, p, n);
		do_sa_sb(stack_a, p, n);
	}
	else if (p->tmp->value < p->tmp->next->value &&
	p->tmp->value > p->tmp->next->next->value)
	{
		do_rra_rrb(stack_a, p, n);
		do_sa_sb(stack_a, p, n);
	}
	else if (p->tmp->value < p->tmp->next->value &&
	p->tmp->value < p->tmp->next->next->value)
		do_rra_rrb(stack_a, p, n);
}

void	push_swap2(t_list **stack_a, t_list **stack_b, t_point *p)
{
	p->tmp = *stack_a;
	p->nbr = p->tmp->value;
	p->tmp2 = *stack_a;
	p->i = 0;
	p->h = (p->middle % 2 == 1) ? p->middle / 2 + 1 : p->middle / 2;
	p->g = p->middle / 2;
	p->middle = p->middle / 2;
	while (p->i != p->middle)
	{
		do_pa_pb(stack_a, stack_b, p, 1);
		p->i++;
	}
	print_lists(stack_a, stack_b, p);
	other_command1(stack_a, p, 0);
	other_command1(stack_b, p, 1);
	print_lists(stack_a, stack_b, p);
	check_push(stack_a, stack_b, p, 4);
}
