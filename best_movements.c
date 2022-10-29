/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:24:19 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:40:29 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_movement_1(t_stack *a_stk, t_stack *b_stk, int a_mov, int b_mov)
{
	while (a_mov < 0)
	{
		ft_rev_rotate(a_stk, a_stk, a_stk->inst);
		a_mov++;
	}
	while (b_mov > 0)
	{
		ft_rotate(a_stk, b_stk, a_stk->inst);
		b_mov--;
	}
}

static void	ft_movement_2(t_stack *a_stk, t_stack *b_stk, int a_mov, int b_mov)
{
	while (a_mov > 0)
	{
		ft_rotate(a_stk, a_stk, a_stk->inst);
		a_mov--;
	}
	while (b_mov < 0)
	{
		ft_rev_rotate(a_stk, b_stk, a_stk->inst);
		b_mov++;
	}
}

static void	ft_movement_3(t_stack *a_stk, t_stack *b_stk, int a_mov, int b_mov)
{
	while (a_mov > 0 && b_mov > 0)
	{
		ft_r_rotate(a_stk, b_stk, a_stk->inst);
		a_mov--;
		b_mov--;
	}
	while (a_mov > 0)
	{
		ft_rotate(a_stk, a_stk, a_stk->inst);
		a_mov--;
	}
	while (b_mov > 0)
	{
		ft_rotate(a_stk, b_stk, a_stk->inst);
		b_mov--;
	}
}

static void	ft_movement_4(t_stack *a_stk, t_stack *b_stk, int a_mov, int b_mov)
{
	while (a_mov < 0 && b_mov < 0)
	{
		ft_r_rev_rotate(a_stk, b_stk, a_stk->inst);
		a_mov++;
		b_mov++;
	}
	while (a_mov < 0)
	{
		ft_rev_rotate(a_stk, a_stk, a_stk->inst);
		a_mov++;
	}
	while (b_mov < 0)
	{
		ft_rev_rotate(a_stk, b_stk, a_stk->inst);
		b_mov++;
	}
}

/* It counts movements for a element in b_stack to its place in a_stack */
/* and find the best way to do both movements on both stacks            */
void	ft_best_movements(t_stack *a_stk, t_stack *b_stk)
{
	t_nod	*tmp;
	int		a_mov;
	int		b_mov;

	while (b_stk->cnt)
	{
		tmp = ft_best_move(b_stk, a_stk);
		b_mov = ft_bestway_top(b_stk, tmp->num, NUM);
		a_mov = ft_bestway_top(a_stk, ft_get_next_rank(a_stk, tmp->rank), RANK);
		if (a_mov <= 0 && b_mov >= 0)
			ft_movement_1(a_stk, b_stk, a_mov, b_mov);
		else if (a_mov >= 0 && b_mov <= 0)
			ft_movement_2(a_stk, b_stk, a_mov, b_mov);
		else if (a_mov > 0 && b_mov > 0)
			ft_movement_3(a_stk, b_stk, a_mov, b_mov);
		else if (a_mov < 0 && b_mov < 0)
			ft_movement_4(a_stk, b_stk, a_mov, b_mov);
		ft_push(a_stk, a_stk, b_stk, a_stk->inst);
	}
}
