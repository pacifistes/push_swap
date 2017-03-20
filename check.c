/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:02:47 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:02:49 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_stack_next(t_point *p)
{
	while (p->tmp2 && p->tmp2->next)
	{
		if (p->tmp2->value < p->tmp2->next->value)
			return (1);
		p->tmp2 = p->tmp2->next;
	}
	return (0);
}

int			ft_check_stack(t_list **stack_a, t_list **stack_b, t_point *p)
{
	print_lists(stack_a, stack_b, p);
	p->tmp2 = *stack_b;
	p->tmp = *stack_a;
	if (p->middle == 3)
	{
		other_command1(stack_a, p, 0);
		return (0);
	}
	while (p->tmp && p->tmp->next)
	{
		if (p->tmp->value < p->tmp->next->value && !p->tmp->next->next &&
		(p->middle == 2 || p->temp->value > p->tmp->next->value))
			return (2);
		if (p->tmp->value == (*stack_a)->value && p->tmp->value <
		p->tmp->next->value && p->tmp->next->next &&
		check_reverse(stack_a) == 0)
			return (4);
		if (p->tmp->value < p->tmp->next->value)
			return (1);
		p->temp = p->tmp;
		p->tmp = p->tmp->next;
	}
	return (ft_check_stack_next(p));
}

void		check_possibility(t_list **stack_a, t_list **stack_b, t_point *p)
{
	p->tmp = *stack_a;
	while (p->tmp->next)
	{
		p->tmp2 = p->tmp;
		p->tmp = p->tmp->next;
	}
	p->o = (p->tmp->value < p->tmp2->value) ? 0 : 1;
	p->tmp = *stack_b;
	while (p->tmp->next)
	{
		p->tmp2 = p->tmp;
		p->tmp = p->tmp->next;
	}
	p->p = (p->tmp->value < p->tmp2->value) ? 0 : 1;
	if (p->o == 1 && p->p == 1)
		do_ss(stack_a, stack_b, p);
	else if (p->o == 1)
		do_sa_sb(stack_a, p, 0);
	else if (p->p == 1)
		do_sa_sb(stack_b, p, 1);
}

void		type_check_push(t_list **stack_a, t_list **stack_b,
t_point *p, int n)
{
	if ((p->tmp->value < p->tmp2->value && p->o != 0) || p->p == 0)
	{
		if (n == 0 || n == 4)
			do_ra_rb(stack_a, p, 0);
		else
		{
			do_pa_pb(stack_a, stack_b, p, 1);
			do_ra_rb(stack_b, p, 1);
		}
		p->o--;
	}
	else
	{
		if (n == 0 || n == 4)
		{
			do_pa_pb(stack_b, stack_a, p, 0);
			do_ra_rb(stack_a, p, 0);
		}
		else
			do_ra_rb(stack_b, p, 1);
		p->p--;
	}
}

void		check_push(t_list **stack_a, t_list **stack_b, t_point *p, int n)
{
	p->o = (n == 3 || n == 4) ? p->h : p->l;
	p->p = (n == 3 || n == 4) ? p->g : p->l;
	while (p->p != 0 || p->o != 0)
	{
		if (*stack_b)
		{
			p->tmp2 = *stack_b;
			while (p->tmp2->next)
				p->tmp2 = p->tmp2->next;
		}
		if (*stack_a)
		{
			p->tmp = *stack_a;
			while (p->tmp->next)
				p->tmp = p->tmp->next;
		}
		type_check_push(stack_a, stack_b, p, n);
	}
}
