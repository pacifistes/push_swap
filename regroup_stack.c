/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regroup_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:08:57 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/04 15:09:01 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	regroup_stack(t_list **stack_a, t_list **stack_b, t_point *p)
{
	p->h = ft_size(stack_a, p);
	p->g = ft_size(stack_b, p);
	if (p->g == p->middle)
	{
		p->g = ft_size(stack_b, p);
		while (*stack_b)
		{
			do_rra_rrb(stack_b, p, 1);
			do_pa_pb(stack_b, stack_a, p, 0);
		}
	}
	else
		check_push(stack_a, stack_b, p, 4);
	if (p->step == 1)
	{
		print_list(*stack_a, p, 0);
		print_list(*stack_b, p, 1);
	}
}
