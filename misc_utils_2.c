/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:35:10 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 22:35:49 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates movements needed to get a number to top, and for moving */
/* its position in the other stack to top                             */
static int	ft_get_distance(t_stack *src, t_stack *dst, t_nod *num)
{
	int	dist_num;
	int	dist_dst;

	dist_num = ft_bestway_top(src, num->num, NUM);
	dist_dst = ft_bestway_top(dst, ft_get_next_rank(dst, num->rank), RANK);
	if (dist_dst * dist_num < 0)
		return (ft_abs(dist_dst) + ft_abs(dist_num));
	else
	{
		if (abs(dist_dst) > abs(dist_num))
			return (abs(dist_dst));
		return (abs(dist_num));
	}
}

/* Finds cheaper element to move an element from b_stack to a_stack */
t_nod	*ft_best_move(t_stack *b_stk, t_stack *a_stk)
{
	t_nod	*best_sofar;
	int		best_cnt;
	t_nod	*tmp;
	int		tmp_cnt;

	tmp = b_stk->first;
	best_sofar = tmp;
	best_cnt = ft_get_distance(b_stk, a_stk, tmp);
	tmp = tmp->next;
	while (tmp)
	{
		tmp_cnt = ft_get_distance(b_stk, a_stk, tmp);
		if (tmp_cnt < best_cnt)
		{
			best_sofar = tmp;
			best_cnt = tmp_cnt;
		}
		tmp = tmp->next;
	}
	return (best_sofar);
}

/* Finds uncommon elements that need less movements to get top */
static t_nod	*ft_best_uncommon(t_stack *a_stk, t_stack *lis)
{
	t_nod	*tmp;
	t_nod	*best;

	tmp = a_stk->last;
	best = NULL;
	while (tmp)
	{
		if (ft_not_here(lis, tmp->num))
		{
			if (!best)
				best = tmp;
			else if (ft_abs(ft_bestway_top(a_stk, tmp->num, NUM))
				< ft_abs(ft_bestway_top(a_stk, best->num, NUM)))
				best = tmp;
		}
		tmp = tmp->prev;
		lis->state = GOOD;
	}
	return (best);
}

/* Moves elements from a_stack to b_stack, that are not in stack lis */
void	ft_move_uncommons(t_stack *a_stk, t_stack *b_stk, t_stack *lis)
{
	t_nod	*best;

	while ((a_stk->cnt - lis->cnt) > 0)
	{
		best = ft_best_uncommon(a_stk, lis);
		if (ft_bestway_top(a_stk, best->num, NUM) >= 0)
			while (ft_get_index(a_stk, best->num, NUM) != 1)
				ft_rotate(a_stk, a_stk, a_stk->inst);
		else
			while (ft_get_index(a_stk, best->num, NUM) != 1)
				ft_rev_rotate(a_stk, a_stk, a_stk->inst);
		ft_push(a_stk, b_stk, a_stk, a_stk->inst);
	}	
}

/* It decides shorter way to top, between moving up (positive value) */
/* or down (negative value) in the stack                             */
int	ft_bestway_top(t_stack *a_stk, int num, int key)
{
	int	index;

	index = ft_get_index(a_stk, num, key);
	if (index == 1)
		return (0);
	if ((a_stk->cnt / 2) + (a_stk->cnt % 2) >= index)
		return (index - 1);
	else
		return (-1 * (a_stk->cnt - index + 1));
}
