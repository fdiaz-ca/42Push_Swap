/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_kases_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:30:53 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:48:30 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* it reads instructions for stack with 6 elements and change SA+SB = SS,... */
void	ft_optimize_code6(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b)
{
	t_nod	*tmp_a;
	t_nod	*tmp_b;
	int		cnt;

	tmp_a = ins_a;
	cnt = 3;
	while (cnt > 0)
	{
		if (tmp_a->num == PB)
			cnt--;
		tmp_a = tmp_a->next;
	}
	while (tmp_a)
	{
		tmp_b = ins_b->next;
		while (tmp_b)
		{
			ft_optimize_code_change(tmp_a, tmp_b);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	ft_add_inst_list(a_stk, ins_a, ins_b);
}

void	ft_optimize_code7_change(t_nod *tmp_a, t_nod *ins_b)
{
	t_nod	*tmp_b;

	while (tmp_a)
	{
		tmp_b = ins_b->next;
		while (tmp_b)
		{
			ft_optimize_code_change(tmp_a, tmp_b);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
}

void	ft_optimize_code7(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b)
{
	t_nod	*tmp_a;
	int		cnt;

	tmp_a = ins_a;
	cnt = 0;
	while (cnt < 3)
	{
		if (tmp_a->num == PB)
			cnt++;
		tmp_a = tmp_a->next;
	}
	while (tmp_a && ((tmp_a->num == PB) || cnt > 3))
	{
		if (tmp_a->num == PB)
			cnt++;
		if (tmp_a->num == PA)
			cnt--;
		tmp_a = tmp_a->next;
	}
	ft_optimize_code7_change(tmp_a, ins_b);
	ft_add_inst_list(a_stk, ins_a, ins_b);
}

/* It takes two stacks, and creates a copy of them */
int	ft_copy_stks(t_stack *a, t_stack *b, t_stack **a_cpy, t_stack **b_cpy)
{
	*a_cpy = ft_copy_stack(a, _A);
	if (!*a_cpy)
	{
		a->state = ERROR;
		return (ERROR);
	}
	if (b_cpy)
	{
		*b_cpy = ft_copy_stack(b, _B);
		if (!*b_cpy)
		{
			a->state = ERROR;
			return (ERROR);
		}
	}
	return (GOOD);
}

/* it reads instructions of two nodes and change SA+SB = SS, and so... */
void	ft_optimize_code_change(t_nod *tmp_a, t_nod *tmp_b)
{
	if (tmp_a->num == SA && tmp_b->num == SB)
	{
		tmp_a->num = SS;
		tmp_b->num = MULTI;
	}
	if (tmp_a->num == RA && tmp_b->num == RB)
	{
		tmp_a->num = RR;
		tmp_b->num = MULTI;
	}
	if (tmp_a->num == RRA && tmp_b->num == RRB)
	{
		tmp_a->num = RRR;
		tmp_b->num = MULTI;
	}
}
