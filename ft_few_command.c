/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_few_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 14:21:43 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/09 14:21:45 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_few_command(t_list **stack_a, t_point *p)
{
	if (p->nbr == 2)
		do_sa_sb(stack_a, p, 0);
	else
	{
		do_rra_rrb(stack_a, p, 0);
		do_rra_rrb(stack_a, p, 0);
		do_sa_sb(stack_a, p, 0);
		do_ra_rb(stack_a, p, 0);
		do_ra_rb(stack_a, p, 0);
	}
}
