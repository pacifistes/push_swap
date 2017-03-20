/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:24:22 by bbrunell          #+#    #+#             */
/*   Updated: 2016/07/04 13:24:25 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# define T p->tmp->next->value < p->tmp->next->next->value

typedef struct		s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int		ac;
	int		i;
	int		compteur;
	char	**av;
	int		color_stack;
	int		middle;
	char	**str;
	int		nbr;
	int		lst;
	int		no_print;
	int		first;
	int		step;
	int		x;
	int		j;
	int		n;
	int		z;
	int		y;
	int		h;
	int		g;
	int		o;
	int		p;
	int		l;
	int		w;
	t_list	*tmp;
	t_list	*temp;
	t_list	*tmp2;
}					t_point;

int					checknumber(t_point *p);
int					ft_error();
int					check_duplicate(t_list *list, int n);
void				do_sa_sb(t_list **stack_a, t_point *p, int n);
void				do_ss(t_list **stack_a, t_list **stack_b, t_point *p);
void				do_pa_pb(t_list **stack_a, t_list **stack_b, t_point *p,
int n);
void				do_ra_rb(t_list **stack_a, t_point *p, int n);
void				do_rr(t_list **stack_a, t_list **stack_b, t_point *p);
void				do_rra_rrb(t_list **stack_a, t_point *p, int n);
void				check_push(t_list **stack_a, t_list **stack_b, t_point *p,
int n);
void				type_check_push(t_list **staw, t_list **staq, t_point *p,
int n);
void				check_possibility(t_list **stack_a, t_list **stack_b,
t_point *p);
int					ft_check_stack(t_list **stack_a, t_list **stack_b,
t_point *p);
int					check_revsab(t_list **stack_a, t_point *p);
int					check_justreverse(t_list **stack_a);
void				other_command1(t_list **stack_a, t_point *p, int n);
void				ft_few_command(t_list **stack_a, t_point *p);
int					ft_size(t_list **list, t_point *p);
void				ft_count(t_list **stack_b, t_point *p, int n);
void				ft_init(t_point *p, int ac, char **av);
void				print_list(t_list *list, t_point *p, int nbr);
t_list				*ft_lstaddint(t_list *list, int nbr);
void				push_swap(t_list **stack_a, t_list **stack_b,
t_point *p);
void				regroup_stack(t_list **stack_a, t_list **stack_b,
t_point *p);
int					check_reverse(t_list **stack_a);
void				push_swap2(t_list **stack_a, t_list **stack_b, t_point *p);
void				print_lists(t_list **stack_a, t_list **stack_b, t_point *p);
void				merge_sort(t_list **stack_a, t_list **stack_b, t_point *p);
void				do_rrr(t_list **stack_a, t_list **stack_b, t_point *p);
void				change_and_verif(t_list **stack_a, t_list **stack_b,
t_point *p);
int					ft_checker(t_list **stack_a, t_list **stack_b, t_point *p);

#endif
