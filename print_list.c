/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:03:20 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:03:29 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list, t_point *p, int nbr)
{
	if (p->color_stack == 1)
		(nbr == 0) ? ft_putstr("\e[0;32m") : ft_putstr("\e[0;31m");
	(nbr == 0) ? ft_putstr("stack a : ") : ft_putstr("stack b : ");
	while (list != NULL)
	{
		ft_putnbr(list->value);
		ft_putchar(' ');
		list = list->next;
	}
	if (p->color_stack == 1)
		ft_putstr("\e[0;0m");
	ft_putstr("\n");
}

void	print_lists(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->step == 1)
	{
		print_list(*stack_a, p, 0);
		print_list(*stack_b, p, 1);
		ft_putstr("\n");
	}
}
