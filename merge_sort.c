/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 14:43:58 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/09 14:44:02 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divise_and_sort(t_list **stack_a, t_list **stack_b, t_point *p)
{
	while (p->j < p->middle / 2)
	{
		do_pa_pb(stack_a, stack_b, p, 1);
		p->j++;
	}
	p->j = 0;
	print_lists(stack_a, stack_b, p);
}

static void	check_the_end(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->w == 1)
		do_ra_rb(stack_b, p, 1);
	if (p->w == 2)
	{
		p->h = 1;
		p->g = 1;
		check_push(stack_a, stack_b, p, 3);
	}
	if (p->w == 3)
	{
		p->tmp = *stack_b;
		while (p->tmp->next)
		{
			p->tmp2 = p->tmp;
			p->tmp = p->tmp->next;
		}
		if (p->tmp->value > p->tmp2->value)
			do_sa_sb(stack_b, p, 1);
		p->h = 1;
		p->g = 2;
		check_push(stack_a, stack_b, p, 3);
	}
	print_lists(stack_a, stack_b, p);
	p->j = (p->w == 0) ? 1 : 0;
	p->l = 2;
}

static void	push_and_checkend(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (p->z == 1)
	{
		p->h = p->l;
		p->g = p->w;
		check_push(stack_a, stack_b, p, 3);
		p->w = p->w + p->l;
	}
	else if (p->w > 0 || p->y == 1)
	{
		p->h = 0;
		if (p->y == 1)
			p->w = p->l;
		while (p->h != p->w)
		{
			do_ra_rb(stack_b, p, 1);
			p->h++;
		}
	}
	change_and_verif(stack_a, stack_b, p);
	p->j = (p->w == 0) ? 1 : 0;
	if (p->z == 1 && p->y == 2 && p->w == 0)
		p->j = 0;
	if (p->z == 1 && p->y == 1 && p->w == 0)
		p->j = -15;
}

static void	push_swap_next(t_list **stack_a, t_list **stack_b, t_point *p)
{
	while (p->y != 0 && p->j != -15)
	{
		while (p->y != 0 && p->z != 0)
		{
			if (p->l == 2)
				check_possibility(stack_a, stack_b, p);
			if (p->j % 2 == 0)
				check_push(stack_a, stack_b, p, 0);
			else
				check_push(stack_a, stack_b, p, 1);
			p->j++;
			p->z--;
			p->y--;
			print_lists(stack_a, stack_b, p);
		}
		push_and_checkend(stack_a, stack_b, p);
		if (p->w > 0 && p->y != 0)
			print_lists(stack_a, stack_b, p);
	}
	regroup_stack(stack_a, stack_b, p);
}

void		merge_sort(t_list **stack_a, t_list **stack_b, t_point *p)
{
	divise_and_sort(stack_a, stack_b, p);
	check_the_end(stack_a, stack_b, p);
	ft_count(stack_a, p, 0);
	ft_count(stack_b, p, 1);
	push_swap_next(stack_a, stack_b, p);
}
