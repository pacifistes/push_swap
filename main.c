/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 18:03:14 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/01 18:03:16 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	go_check_r(t_list **stack_a, t_list **stack_b, t_point *p,
char **line)
{
	if (ft_strcmp("ra", *line) == 0)
		do_ra_rb(stack_a, p, 0);
	else if (ft_strcmp("rb", *line) == 0)
		do_ra_rb(stack_b, p, 1);
	else if (ft_strcmp("rr", *line) == 0)
		do_rr(stack_a, stack_b, p);
	else if (ft_strcmp("rra", *line) == 0)
		do_rra_rrb(stack_a, p, 0);
	else if (ft_strcmp("rrb", *line) == 0)
		do_ra_rb(stack_b, p, 1);
	else if (ft_strcmp("rrr", *line) == 0)
		do_rrr(stack_a, stack_b, p);
	else if (ft_strcmp("pb", *line) == 0)
		do_pa_pb(stack_a, stack_b, p, 1);
	else if (ft_strcmp("pa", *line) == 0)
		do_pa_pb(stack_b, stack_a, p, 0);
}

int			go_check(t_list **stack_a, t_list **stack_b, t_point *p)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp("sa", line) == 0)
			do_sa_sb(stack_a, p, 0);
		else if (ft_strcmp("sb", line) == 0)
			do_sa_sb(stack_b, p, 1);
		else if (ft_strcmp("ss", line) == 0)
			do_ss(stack_a, stack_b, p);
		else if (!ft_strcmp("ra", line) || !ft_strcmp("rb", line) ||
		!ft_strcmp("rr", line) || !ft_strcmp("rra", line) ||
		!ft_strcmp("rrb", line) || !ft_strcmp("rrr", line) ||
		!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
			go_check_r(stack_a, stack_b, p, &line);
		else
		{
			ft_strdel(&line);
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		ft_strdel(&line);
	}
	return (0);
}

void		go_push(t_list **stack_a, t_list **stack_b, t_point *p)
{
	if (ft_strcmp("./checker", p->av[0]) == 0 && p->middle > 1)
	{
		p->no_print = 1;
		if (go_check(stack_a, stack_b, p) == -1)
			return ;
		(ft_checker(stack_a, stack_b, p) == 0) ? ft_putstr("OK\n") :
		ft_putstr("KO\n");
	}
	else
	{
		if (p->middle > 1)
			push_swap(stack_a, stack_b, p);
		if (p->lst)
		{
			ft_putstr("/* ---FINAL--- */\n");
			print_list(*stack_a, p, 0);
			print_list(*stack_b, p, 1);
		}
		if (p->compteur != -1)
		{
			ft_putstr("compteur : ");
			ft_putnbr(p->compteur);
			ft_putchar('\n');
		}
	}
}

static int	mid_main(t_point *p, t_list **stack_a, char **av, int ac)
{
	while (p->i + 1 < ac)
	{
		p->w = 0;
		p->str = ft_strsplit(av[p->i + 1], ' ');
		while (p->str[p->w])
		{
			*stack_a = ft_lstaddint(*stack_a, ft_atoi(p->str[p->w]));
			if ((check_duplicate(*stack_a, ft_atoi(p->str[p->w])) == 1) ||
			ft_verifint(p->str[p->w]) == 2147484848)
				return (0);
			ft_strdel(&p->str[p->w]);
			p->w++;
		}
		free(p->str);
		p->str = NULL;
		p->i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_point p;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1 && (ft_strcmp("./push_swap", av[0]) == 0 ||
	ft_strcmp("./checker", av[0]) == 0))
	{
		stack_a = NULL;
		stack_b = NULL;
		ft_init(&p, ac, av);
		if (checknumber(&p) == -1)
			return (ft_error());
		if (!mid_main(&p, &stack_a, av, ac) || !stack_a)
			return (ft_error());
		if (p.first == 1)
			print_list(stack_a, &p, 0);
		p.middle = ft_size(&stack_a, &p);
		go_push(&stack_a, &stack_b, &p);
	}
	else if (ft_strcmp("./push_swap", av[0]) == 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
