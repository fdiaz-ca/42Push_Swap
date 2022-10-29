/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:27:58 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:43:19 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return the abosulute value of an integer */
int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

/* Makes a code depending on positions of rank of numbers in a stack */
/* for example: "54 7 21" stack generates a '312' code               */
int	ft_read_code(t_nod *nod)
{
	int	i;

	i = 0;
	while (nod)
	{
		i = (10 * i) + nod->rank;
		nod = nod->next;
	}
	return (i);
}

/* It gets the maximum and minimum numbers in a stack */
static void	ft_get_max_rank(t_stack *stk, int *min, int *max)
{
	t_nod	*tmp;

	tmp = stk->first;
	*min = tmp->rank;
	*max = tmp->rank;
	while (tmp)
	{
		if (tmp->rank < *min)
			*min = tmp->rank;
		if (tmp->rank > *max)
			*max = tmp->rank;
		tmp = tmp->next;
	}
}

/* It finds next rank (to move to top before doing a push) */
int	ft_get_next_rank(t_stack *stk, int rank)
{
	int		min;
	int		next;
	int		max;
	t_nod	*tmp;

	ft_get_max_rank(stk, &min, &max);
	if (rank >= max)
		return (min);
	else
	{
		tmp = stk->first;
		next = 0;
		while (tmp)
		{
			if (rank < tmp->rank && (tmp->rank < next || !next))
				next = tmp->rank;
			tmp = tmp->next;
		}
	}
	return (next);
}

/* Copy instruction of a list on another, a_stk for error control */
void	ft_add_inst_list(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b)
{
	t_nod	*tmp;

	tmp = ins_b;
	while (tmp)
	{
		if (tmp->num >= PA && tmp->num <= RRR)
			ft_add_inst(a_stk, ins_a, tmp->num);
		tmp = tmp->next;
	}
	ft_clear_list(&(ins_b->next));
}
