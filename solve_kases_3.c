/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_kases_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:22:57 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:59:59 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* it reads instructions for stack with 5 elements and change SA+SB = SS,... */
static void	ft_optimize_code5(t_stack *a_stk, t_stack *b_stk)
{
	int		code_b;
	t_nod	*tmp;

	code_b = ft_read_code(b_stk->first);
	if (code_b == 12)
	{
		tmp = a_stk->inst;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->num != PB)
		{
			if (tmp->num == SA)
				tmp->num = SS;
			if (tmp->num == RA)
				tmp->num = RR;
			if (tmp->num == RRA)
				tmp->num = RRR;
			ft_rotate(a_stk, b_stk, NULL);
		}
		else
			ft_rotate(a_stk, b_stk, a_stk->inst);
	}
}

/* It repeats push operation 'rep' times */
static void	ft_rep_pa(t_stack *a_stk, t_stack *b_stk, t_nod *ins, int rep)
{
	while (rep > 0)
	{
		ft_push(a_stk, a_stk, b_stk, ins);
		rep--;
	}
}

/* Solve the case of stack with 7 elements, dividing it in kase3 and kase4 */
void	ft_solve_kase7_1(t_stack *a_stk, t_stack *b_stk, int code_a)
{
	t_stack	*aux;
	int		code_b;

	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_remove_min(a_stk, aux, 3);
	ft_move_uncommons(a_stk, b_stk, aux);
	ft_clear_stacks(&aux, NULL);
	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_number_stack(aux);
	code_a = ft_read_code(aux->first);
	ft_solve_kase4(a_stk, b_stk, code_a);
	code_b = ft_read_code(b_stk->first);
	ft_solve_kase3(a_stk, b_stk, code_b, b_stk->inst);
	ft_optimize_code7(a_stk, a_stk->inst, b_stk->inst);
	ft_rep_pa(a_stk, b_stk, a_stk->inst, 3);
	ft_clear_stacks(&aux, NULL);
}

/* Solve the case of stack with 6 elements, dividing it in 2 kase3 */
void	ft_solve_kase6_1(t_stack *a_stk, t_stack *b_stk, int code_a)
{
	t_stack	*aux;
	int		code_b;

	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_remove_min(a_stk, aux, 3);
	ft_move_uncommons(a_stk, b_stk, aux);
	ft_clear_stacks(&aux, NULL);
	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_number_stack(aux);
	code_a = ft_read_code(aux->first);
	ft_solve_kase3(a_stk, a_stk, code_a, a_stk->inst);
	code_b = ft_read_code(b_stk->first);
	ft_solve_kase3(a_stk, b_stk, code_b, b_stk->inst);
	ft_optimize_code6(a_stk, a_stk->inst, b_stk->inst);
	ft_rep_pa(a_stk, b_stk, a_stk->inst, 3);
	ft_clear_stacks(&aux, NULL);
}

/* Solve the case of stack with 5 elements */
void	ft_solve_kase5_1(t_stack *a_stk, t_stack *b_stk)
{
	t_stack	*aux;
	int		code;

	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_remove_min(a_stk, aux, 2);
	ft_move_uncommons(a_stk, b_stk, aux);
	ft_clear_stacks(&aux, NULL);
	if (ft_copy_stks(a_stk, b_stk, &aux, NULL) == ERROR)
		return ;
	ft_number_stack(aux);
	code = ft_read_code(aux->first);
	ft_clear_stacks(&aux, NULL);
	ft_solve_kase3(a_stk, a_stk, code, a_stk->inst);
	ft_optimize_code5(a_stk, b_stk);
	ft_rep_pa(a_stk, b_stk, a_stk->inst, 2);
}
