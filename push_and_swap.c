/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:03:37 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:03:42 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sa_sb_next(t_list **stack_a, t_point *p)
{
	if (p->temp->value != p->tmp2->value)
	{
		while (p->temp->next->value != p->tmp2->value)
			p->temp = p->temp->next;
		p->temp->next = p->tmp;
		p->tmp2->next = NULL;
		p->tmp->next = p->tmp2;
	}
	else
	{
		p->tmp->next = p->tmp2;
		p->tmp2->next = NULL;
		*stack_a = p->tmp;
	}
}

void		do_sa_sb(t_list **stack_a, t_point *p, int n)
{
	p->tmp = *stack_a;
	p->temp = *stack_a;
	if (p->no_print == 0 && n != -1)
		(n == 0) ? ft_putstr("sa\n") : ft_putstr("sb\n");
	p->compteur = (n == -1 || p->compteur == -1) ?
	p->compteur : p->compteur + 1;
	if (p->tmp != NULL && p->tmp->next != NULL)
	{
		while (p->tmp->next != NULL)
		{
			p->tmp2 = p->tmp;
			p->tmp = p->tmp->next;
		}
		do_sa_sb_next(stack_a, p);
	}
}

void		do_ss(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->no_print == 0)
		ft_putstr("ss\n");
	do_sa_sb(stack_a, p, -1);
	do_sa_sb(stack_b, p, -1);
	p->compteur = (p->compteur == -1) ? p->compteur : p->compteur + 1;
}

static void	do_pa_pb_next(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->temp)
	{
		while (p->temp->next != NULL)
			p->temp = p->temp->next;
		p->temp->next = p->tmp;
		if (p->x == 0)
			p->tmp2->next = p->tmp->next;
		else
			*stack_a = p->tmp->next;
	}
	else
	{
		*stack_b = p->tmp;
		if (p->x == 0)
			p->tmp2->next = p->tmp->next;
		else
			*stack_a = p->tmp->next;
	}
}

void		do_pa_pb(t_list **stack_a, t_list **stack_b, t_point *p, int n)
{
	p->tmp = *stack_a;
	p->temp = *stack_b;
	p->x = 0;
	if (p->no_print == 0 && n != -1)
		(n == 0) ? ft_putstr("pa\n") : ft_putstr("pb\n");
	p->compteur = (n == -1 || p->compteur == -1) ? p->compteur :
	p->compteur + 1;
	if (p->tmp != NULL)
	{
		if (p->tmp->next == NULL)
			p->x = 1;
		while (p->tmp->next != NULL)
		{
			p->tmp2 = p->tmp;
			p->tmp = p->tmp->next;
		}
		do_pa_pb_next(stack_a, stack_b, p);
	}
}
