/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_kases_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:24:00 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 22:03:00 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Solve the case of stack with 4 elements */
static void	ft_solve_kase4_4(t_stack *a_stk, int k, t_nod *ins)
{
	if (k == 4231)
		ft_rev_rotate(a_stk, a_stk, ins);
	if (k == 4231 || k == 4312 || k == 4321)
		ft_swap(a_stk, a_stk, ins);
	if (k == 4123 || k == 4132 || k == 4213 || k == 4312 || k == 4321)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 4132 || k == 4231 || k == 4312 || k == 4321)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 4132 || k == 4213 || k == 4321)
		ft_swap(a_stk, a_stk, ins);
	if (k == 4132)
		ft_rev_rotate(a_stk, a_stk, ins);
}

/* Solve the case of stack with 4 elements */
static void	ft_solve_kase4_3(t_stack *a_stk, int k, t_nod *ins)
{
	if (k == 3142 || k == 3412 || k == 3421)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 3214 || k == 3142 || k == 3241)
		ft_swap(a_stk, a_stk, ins);
	if (k == 3124 || k == 3214 || k == 3241)
		ft_rev_rotate(a_stk, a_stk, ins);
	if (k == 3142 || k == 3412 || k == 3421)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 3214)
		ft_rev_rotate(a_stk, a_stk, ins);
	if (k == 3124 || k == 3214 || k == 3421)
		ft_swap(a_stk, a_stk, ins);
	if (k == 3124 || k == 3214)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 3124)
		ft_rotate(a_stk, a_stk, ins);
}

/* Solve the case of stack with 4 elements */
static void	ft_solve_kase4_2(t_stack *a_stk, t_stack *b_stk, int k, t_nod *ins)
{
	if (k == 2143 || k == 2413 || k == 2431)
		ft_push(a_stk, b_stk, a_stk, ins);
	if (k == 2431)
		ft_swap(a_stk, a_stk, ins);
	if (k == 2413 || k == 2314)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 2314)
		ft_rotate(a_stk, a_stk, ins);
	if (k == 2143)
	{
		ft_push(a_stk, b_stk, a_stk, ins);
		ft_s_swap(a_stk, b_stk, ins);
		ft_push(a_stk, a_stk, b_stk, ins);
	}
	if (k == 2143 || k == 2413 || k == 2431)
		ft_push(a_stk, a_stk, b_stk, ins);
	if (k == 2341 || k == 2431)
		ft_rev_rotate(a_stk, a_stk, ins);
	if (k == 2134 || k == 2413 || k == 2314)
		ft_swap(a_stk, a_stk, ins);
	if (k == 2314)
		ft_rotate(a_stk, a_stk, ins);
}

/* Solve the case of stack with 4 elements */
static void	ft_solve_kase4_1(t_stack *a_stk, t_stack *b_stk, int k, t_nod *ins)
{
	if (k == 1243 || k == 1324 || k == 1342 || k == 1432)
	{
		ft_push(a_stk, b_stk, a_stk, ins);
		if (k == 1243)
			ft_push(a_stk, b_stk, a_stk, ins);
		if (k == 1432)
			ft_rotate(a_stk, a_stk, ins);
		if (k == 1243 || k == 1324 || k == 1432)
		{
			ft_swap(a_stk, a_stk, ins);
			ft_push(a_stk, a_stk, b_stk, ins);
			if (k == 1432)
				ft_push(a_stk, a_stk, b_stk, ins);
		}
	}
	if (k == 1342)
		ft_rev_rotate(a_stk, a_stk, ins);
	if (k == 1342 || k == 1243)
		ft_push(a_stk, a_stk, b_stk, ins);
	if (k == 1423)
	{
		ft_swap(a_stk, a_stk, ins);
		ft_rotate(a_stk, a_stk, ins);
	}
}

/* Solve the case of stack with 4 elements */
void	ft_solve_kase4(t_stack *a_stk, t_stack *b_stk, int code)
{
	int	subcode;

	subcode = code / 1000;
	if (subcode == 1)
		ft_solve_kase4_1(a_stk, b_stk, code, a_stk->inst);
	else if (subcode == 2)
		ft_solve_kase4_2(a_stk, b_stk, code, a_stk->inst);
	else if (subcode == 3)
		ft_solve_kase4_3(a_stk, code, a_stk->inst);
	else if (subcode == 4)
		ft_solve_kase4_4(a_stk, code, a_stk->inst);
}
