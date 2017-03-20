/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:04:43 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:04:45 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')
	|| (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9' && (i == 0 ||
	str[i - 1] == ' '))))
		i++;
	if (str[i] == '\0' && i == 0)
		return (0);
	return ((str[i] == '\0') ? 1 : 0);
}

int			checknumber(t_point *p)
{
	while (p->i <= p->ac && (!ft_strcmp("-n", p->av[p->i]) ||
	!ft_strcmp("-s", p->av[p->i]) || !ft_strcmp("-c", p->av[p->i]) ||
	!ft_strcmp("-o", p->av[p->i]) || !ft_strcmp("-v", p->av[p->i]) ||
	!ft_strcmp("-f", p->av[p->i])))
	{
		p->compteur = (!ft_strcmp("-n", p->av[p->i])) ? 0 : p->compteur;
		p->color_stack = (!ft_strcmp("-c", p->av[p->i])) ? 1 : p->color_stack;
		p->lst = (!ft_strcmp("-o", p->av[p->i])) ? 1 : p->lst;
		p->no_print = (!ft_strcmp("-s", p->av[p->i])) ? 1 : p->no_print;
		p->step = (!ft_strcmp("-v", p->av[p->i])) ? 1 : p->step;
		p->first = (!ft_strcmp("-f", p->av[p->i])) ? 1 : p->first;
		p->i++;
		p->middle++;
	}
	while (p->i <= p->ac && ft_isnumber(p->av[p->i]) == 1)
		p->i++;
	p->middle = (p->i - p->middle - 1);
	p->i = (p->i > p->ac) ? p->i - 1 - p->middle : -1;
	return (p->i);
}

int			ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			check_duplicate(t_list *list, int n)
{
	list = list->next;
	while (list != NULL)
	{
		if (n == list->value)
			return (1);
		list = list->next;
	}
	return (0);
}

int			ft_checker(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (*stack_b)
		return (1);
	p->tmp = *stack_a;
	while (p->tmp && p->tmp->next)
	{
		if (p->tmp->value < p->tmp->next->value)
			return (1);
		p->tmp = p->tmp->next;
	}
	return (0);
}
