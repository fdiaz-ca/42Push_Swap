/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:17:03 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 04:37:07 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_copy_stack(t_stack *stk, int name)
{
	t_stack	*aux;
	t_nod	*tmp;

	aux = ft_init_stack(name);
	if (!aux)
		return (NULL);
	tmp = stk->first;
	while (tmp)
	{
		ft_create_last(aux, tmp->num);
		if (aux->state == ERROR)
		{
			ft_clear_stacks(&aux, NULL);
			return (NULL);
		}
		aux->last->rank = tmp->rank;
		tmp = tmp->next;
	}
	return (aux);
}

void	ft_min_to_the_top(t_stack *a_stk, t_stack *stk, t_nod *ins)
{
	int		minimal;
	int		min_move;

	minimal = 1;
	while (!ft_get_index(stk, minimal, RANK))
		minimal++;
	min_move = ft_bestway_top(stk, minimal, RANK);
	while (min_move++ < 0)
		ft_rev_rotate(a_stk, stk, ins);
	while (--min_move > 0)
		ft_rotate(a_stk, stk, ins);
}

static t_lis	*ft_find_longest_lis(t_lis *lis)
{
	t_lis	*best;

	best = lis;
	while (lis)
	{
		if (lis->rank > best->rank)
			best = lis;
		lis = lis->prox;
	}
	return (best);
}

t_lis	*ft_lis1(t_lis *lis)
{
	t_lis	*tmp;
	t_lis	*mark;

	mark = lis;
	while (mark->prox)
		mark = mark->prox;
	while (mark)
	{
		tmp = mark;
		while (tmp)
		{
			if (tmp->num > mark->num && tmp->rank >= mark->rank)
			{
				mark->next = tmp;
				mark->rank = tmp->rank + 1;
			}
			tmp = tmp->prox;
		}
		mark = mark->prev;
	}
	return (ft_find_longest_lis(lis));
}

t_lis	*ft_lis2(t_lis *lis)
{
	t_lis	*tmp;
	t_lis	*mark;

	mark = lis;
	while (mark)
	{
		tmp = mark;
		while (tmp)
		{
			if (tmp->num < mark->num && tmp->rank >= mark->rank)
			{
				mark->next = tmp;
				mark->rank = tmp->rank + 1;
			}
			tmp = tmp->prev;
		}
		mark = mark->prox;
	}
	return (ft_find_longest_lis(lis));
}
