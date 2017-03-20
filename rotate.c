/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:04:32 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:04:35 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_rb(t_list **stack_a, t_point *p, int n)
{
	p->tmp = *stack_a;
	p->compteur = (n == -1 || p->compteur == -1) ? p->compteur :
	p->compteur + 1;
	if (p->no_print == 0 && n != -1)
		(n == 0) ? ft_putstr("ra\n") : ft_putstr("rb\n");
	if (p->tmp != NULL && p->tmp->next != NULL)
	{
		while (p->tmp->next != NULL)
		{
			p->temp = p->tmp;
			p->tmp = p->tmp->next;
		}
		p->temp->next = NULL;
		p->tmp->next = *stack_a;
		*stack_a = p->tmp;
	}
}

void	do_rr(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->no_print == 0)
		ft_putstr("rr\n");
	do_ra_rb(stack_a, p, -1);
	do_ra_rb(stack_b, p, -1);
	p->compteur = (p->compteur == -1) ? p->compteur : p->compteur + 1;
}

void	do_rra_rrb(t_list **stack_a, t_point *p, int n)
{
	p->tmp = *stack_a;
	p->temp = *stack_a;
	if (p->no_print == 0 && n != -1)
		(n == 0) ? ft_putstr("rra\n") : ft_putstr("rrb\n");
	p->compteur = (n == -1 || p->compteur == -1) ? p->compteur :
	p->compteur + 1;
	if (p->tmp != NULL && p->tmp->next != NULL)
	{
		p->tmp2 = p->tmp->next;
		while (p->tmp->next != NULL)
			p->tmp = p->tmp->next;
		p->tmp->next = p->temp;
		p->temp->next = NULL;
		*stack_a = p->tmp2;
	}
}

void	do_rrr(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->no_print == 0)
		ft_putstr("rrr\n");
	do_rra_rrb(stack_a, p, -1);
	do_rra_rrb(stack_b, p, -1);
	p->compteur = (p->compteur == -1) ? p->compteur : p->compteur + 1;
}
