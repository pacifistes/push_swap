/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:03:05 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:03:07 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_size(t_list **list, t_point *p)
{
	int i;

	i = 0;
	p->tmp = *list;
	while (p->tmp)
	{
		i++;
		p->tmp = p->tmp->next;
	}
	return (i);
}

void	ft_count(t_list **stack_b, t_point *p, int n)
{
	int i;

	i = 0;
	p->tmp = *stack_b;
	while (p->tmp)
	{
		p->tmp = p->tmp->next;
		i++;
	}
	if (n == 1)
	{
		i = i - p->w;
		p->y = i / p->l;
	}
	else
		p->z = i / p->l;
}

void	ft_init(t_point *p, int ac, char **av)
{
	p->i = 1;
	p->ac = ac - 1;
	p->av = av;
	p->compteur = -1;
	p->color_stack = 0;
	p->middle = 0;
	p->lst = 0;
	p->no_print = 0;
	p->h = 0;
	p->g = 0;
	p->first = 0;
}

int		check_reverse(t_list **stack_a)
{
	t_list	*tmp;
	int		n;

	tmp = *stack_a;
	n = tmp->value;
	tmp = tmp->next->next;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value || tmp->value > n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	change_and_verif(t_list **stack_a, t_list **stack_b, t_point *p)
{
	p->l = p->l * 2;
	ft_count(stack_a, p, 0);
	ft_count(stack_b, p, 1);
	if (p->w == 0 && p->y == (p->z + 1))
	{
		p->h = 0;
		p->w = p->l;
		while (p->h != p->w)
		{
			do_ra_rb(stack_b, p, 1);
			p->h++;
		}
		ft_count(stack_a, p, 0);
		ft_count(stack_b, p, 1);
	}
}
