/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:30:36 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:47:06 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Add instruction at the end of instruction list */
/* it recives tha a_stk, to control errors        */
void	ft_add_inst(t_stack *a_stk, t_nod *ins, int inst)
{
	t_nod	*tmp;
	int		*cnt;

	if (ins)
	{
		tmp = (t_nod *)malloc(sizeof(t_nod));
		if (!tmp)
		{
			a_stk->state = ERROR;
			return ;
		}
		tmp->num = inst;
		tmp->next = NULL;
		cnt = &(ins->rank);
		while (ins->next)
			ins = ins->next;
		ins->next = tmp;
		tmp->rank = ins->rank + 1;
		*cnt += 1;
	}
}

/* It adds a node into a stack, in top or bottom, according value of place */
void	ft_add_nod(t_stack *stk, int place, t_nod *nod)
{
	if (!stk->first)
	{
		stk->last = nod;
		stk->first = nod;
		nod->next = NULL;
		nod->prev = NULL;
	}
	else if (place == INTOP)
	{
		nod->prev = NULL;
		nod->next = stk->first;
		stk->first->prev = nod;
		stk->first = nod;
	}
	else if (place == INBOT)
	{
		nod->prev = stk->last;
		nod->next = NULL;
		stk->last->next = nod;
		stk->last = nod;
	}
	stk->cnt += 1;
}

/* It removes a node of a stack, in top or bottom, according value of place */
t_nod	*ft_rem_nod(t_stack *stk, int place)
{
	t_nod	*tmp;

	tmp = NULL;
	if (stk->first == stk->last)
	{
		tmp = stk->first;
		stk->first = NULL;
		stk->last = NULL;
	}
	else if (place == INTOP)
	{
		tmp = stk->first;
		stk->first = tmp->next;
		stk->first->prev = NULL;
	}
	else if (place == INBOT)
	{
		tmp = stk->last;
		stk->last = tmp->prev;
		stk->last->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	stk->cnt -= 1;
	return (tmp);
}

/* AQUI EMPIEZA FUNCIONES DE PILA */
/* Swap operation, for a or b stack, a_stk for error control */
void	ft_swap(t_stack *a_stk, t_stack *stk, t_nod *ins)
{
	t_nod	*tmp1;
	t_nod	*tmp2;

	if (stk->cnt > 1)
	{
		tmp1 = ft_rem_nod(stk, INTOP);
		tmp2 = ft_rem_nod(stk, INTOP);
		ft_add_nod(stk, INTOP, tmp1);
		ft_add_nod(stk, INTOP, tmp2);
		if (stk->name == _A)
			ft_add_inst(a_stk, ins, SA);
		else if (stk->name == _B)
			ft_add_inst(a_stk, ins, SB);
	}
}

/* Swap operation, for a and b stack, a_stk for error control */
void	ft_s_swap(t_stack *a_stk, t_stack *b_stk, t_nod *ins)
{
	ft_swap(a_stk, a_stk, NULL);
	ft_swap(a_stk, b_stk, NULL);
	ft_add_inst(a_stk, ins, SS);
}
