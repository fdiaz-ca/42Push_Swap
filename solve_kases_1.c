/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_kases_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:28:27 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 05:24:19 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* It puts the minimum number on the top, and removes it */
void	ft_remove_min(t_stack *a_stk, t_stack *stk, int rep)
{
	t_nod	*tmp;

	while (rep > 0)
	{
		ft_min_to_the_top(a_stk, stk, NULL);
		tmp = ft_rem_nod(stk, INTOP);
		free(tmp);
		rep--;
	}
}

/* It makes a copy of stacks to sort with Solve_kase7 algorithm and also do */
/* it with lis_algorithm, and solves it with best result                    */
void	ft_solve_kase7(t_stack *a_stk, t_stack *b_stk, int code_a)
{
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		with_lis;
	int		with_kase;

	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_solve_kase7_1(a_cpy, b_cpy, code_a);
	with_kase = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_lis_algorithm(&a_cpy, b_cpy);
	with_lis = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (with_kase < with_lis)
		ft_solve_kase7_1(a_stk, b_stk, code_a);
	else
		ft_lis_algorithm(&a_stk, b_stk);
}

/* It makes a copy of stacks to sort with Solve_kase6 algorithm and also do */
/* it with lis_algorithm, and solves it with best result                    */
void	ft_solve_kase6(t_stack *a_stk, t_stack *b_stk, int code_a)
{
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		with_lis;
	int		with_kase;

	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_solve_kase6_1(a_cpy, b_cpy, code_a);
	with_kase = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_lis_algorithm(&a_cpy, b_cpy);
	with_lis = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (with_kase < with_lis)
		ft_solve_kase6_1(a_stk, b_stk, code_a);
	else
		ft_lis_algorithm(&a_stk, b_stk);
}

/* It makes a copy of stacks to sort with Solve_kase5 algorithm and also do */
/* it with lis_algorithm, and solves it with best result                    */
void	ft_solve_kase5(t_stack *a_stk, t_stack *b_stk)
{
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		with_lis;
	int		with_kase;

	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_solve_kase5_1(a_cpy, b_cpy);
	with_kase = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (ft_copy_stks(a_stk, b_stk, &a_cpy, &b_cpy) == ERROR)
		return ;
	ft_lis_algorithm(&a_cpy, b_cpy);
	with_lis = a_cpy->inst->rank;
	ft_clear_stacks(&a_cpy, &b_cpy);
	if (with_kase < with_lis)
		ft_solve_kase5_1(a_stk, b_stk);
	else
		ft_lis_algorithm(&a_stk, b_stk);
}

/* Solve the case of stack with 3 elements */
void	ft_solve_kase3(t_stack *a_stk, t_stack *stk, int k, t_nod *ins)
{
	if (k != 1)
	{
		if ((stk->name == _A && (k == 21 || k == 213 || k == 132 || k == 321))
			|| (stk->name == _B
				&& (k == 12 || k == 123 || k == 312 || k == 231)))
		{
			ft_swap(a_stk, stk, ins);
			if ((stk->name == _A && k == 132) || (stk->name == _B && k == 312))
				ft_rotate(a_stk, stk, ins);
			if ((stk->name == _A && k == 321) || (stk->name == _B && k == 123))
				ft_rev_rotate(a_stk, stk, ins);
		}
		if ((stk->name == _A && k == 312) || (stk->name == _B && k == 132))
			ft_rotate(a_stk, stk, ins);
		if ((stk->name == _A && k == 231) || (stk->name == _B && k == 213))
			ft_rev_rotate(a_stk, stk, ins);
	}
}
