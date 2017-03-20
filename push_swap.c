/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:04:20 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:04:22 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, t_point *p)
{
	p->nbr = ft_check_stack(stack_a, stack_b, p);
	if (p->nbr == 0)
		return ;
	if (p->nbr == 2 || p->nbr == 4)
	{
		ft_few_command(stack_a, p);
		return ;
	}
	if (p->middle >= 3 && p->middle <= 6)
	{
		(p->middle == 3) ? other_command1(stack_a, p, 0) :
		push_swap2(stack_a, stack_b, p);
		return ;
	}
	p->tmp = *stack_a;
	p->j = p->middle % 2 == 1 ? -1 : 0;
	p->w = 0;
	if ((p->middle / 2) % 2 == 1)
		p->w = (p->middle % 2 == 1 && (p->middle / 2) % 2 == 1) ? 3 : 2;
	else if (p->middle % 2 == 1)
		p->w = 1;
	merge_sort(stack_a, stack_b, p);
}
