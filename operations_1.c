/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:29:24 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 15:30:15 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push operation, for a or b stack, a_stk for error control */
void	ft_push(t_stack *a_stk, t_stack *pri, t_stack *sec, t_nod *ins)
{
	t_nod	*tmp;

	if (sec->cnt > 0)
	{
		tmp = ft_rem_nod(sec, INTOP);
		ft_add_nod(pri, INTOP, tmp);
		if (pri->name == _A)
			ft_add_inst(a_stk, ins, PA);
		else if (pri->name == _B)
			ft_add_inst(a_stk, ins, PB);
	}
}

/* Reverse rotate operation, for a or b stack, a_stk for error control */
void	ft_rev_rotate(t_stack *a_stk, t_stack *stk, t_nod *ins)
{
	t_nod	*tmp;

	if (stk->cnt > 1)
	{
		tmp = ft_rem_nod(stk, INBOT);
		ft_add_nod(stk, INTOP, tmp);
		if (stk->name == _A)
			ft_add_inst(a_stk, ins, RRA);
		else if (stk->name == _B)
			ft_add_inst(a_stk, ins, RRB);
	}
}

/* Reverse rotate operation, for a and b stack, a_stk for error control */
void	ft_r_rev_rotate(t_stack *a_stk, t_stack *b_stk, t_nod *ins)
{
	ft_rev_rotate(a_stk, a_stk, NULL);
	ft_rev_rotate(a_stk, b_stk, NULL);
	ft_add_inst(a_stk, ins, RRR);
}

/* Rotate operation, for a or b stack, a_stk for error control */
void	ft_rotate(t_stack *a_stk, t_stack *stk, t_nod *ins)
{
	t_nod	*tmp;

	if (stk->cnt > 1)
	{
		tmp = ft_rem_nod(stk, INTOP);
		ft_add_nod(stk, INBOT, tmp);
		if (stk->name == _A)
			ft_add_inst(a_stk, ins, RA);
		else if (stk->name == _B)
			ft_add_inst(a_stk, ins, RB);
	}
}

/* Rotate operation, for a and b stack, a_stk for error control */
void	ft_r_rotate(t_stack *a_stk, t_stack *b_stk, t_nod *ins)
{
	ft_rotate(a_stk, a_stk, NULL);
	ft_rotate(a_stk, b_stk, NULL);
	ft_add_inst(a_stk, ins, RR);
}
/* HASTA AQUI FUNCIONES DE PILA */
