/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:17:03 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 06:19:44 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lis_algorithm2(t_stack *a_stk, t_stack *b_stk)
{
	t_stack	*lis;

	lis = ft_get_lis2(a_stk);
	if (!lis)
	{
		a_stk->state = ERROR;
		return ;
	}
	ft_move_uncommons(a_stk, b_stk, lis);
	ft_clear_stacks(&lis, NULL);
	ft_best_movements(a_stk, b_stk);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

static void	ft_lis_algorithm1(t_stack *a_stk, t_stack *b_stk)
{
	t_stack	*lis;

	lis = ft_get_lis1(a_stk);
	if (!lis)
	{
		a_stk->state = ERROR;
		return ;
	}
	ft_move_uncommons(a_stk, b_stk, lis);
	ft_clear_stacks(&lis, NULL);
	ft_best_movements(a_stk, b_stk);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

void	ft_lis_algorithm(t_stack **a_stk1, t_stack *b_stk)
{
	t_stack	*a_stk2;
	t_stack	*b_stk2;

	if (ft_copy_stks(*a_stk1, b_stk, &a_stk2, &b_stk2) == ERROR)
		return ;
	ft_lis_algorithm2(a_stk2, b_stk2);
	ft_lis_algorithm1((*a_stk1), b_stk);
	if ((*a_stk1)->state == ERROR || a_stk2->state == ERROR)
	{
		(*a_stk1)->state = ERROR;
		ft_clear_stacks(&a_stk2, &b_stk2);
		return ;
	}
	if ((*a_stk1)->inst->rank < a_stk2->inst->rank)
		ft_clear_stacks(&a_stk2, &b_stk2);
	else
	{
		ft_clear_list(&((*a_stk1)->inst));
		(*a_stk1)->inst = a_stk2->inst;
		ft_clear_list(&(a_stk2->first));
		free(a_stk2);
		ft_clear_stacks(&b_stk2, NULL);
	}
}
