/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:20:42 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 06:14:17 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* tipical calloc */
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if ((size >= SIZE_MAX && count > 1) || (count >= SIZE_MAX && size > 1))
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}

/* Second part of print_inst to fit in 25 lines functions */
static void	ft_print_inst2(t_nod *nod)
{
	if (nod->num == RRA)
		write(1, "rra\n", 4);
	else if (nod->num == RRB)
		write(1, "rrb\n", 4);
	else if (nod->num == RRR)
		write(1, "rrr\n", 4);
	else if (nod->num == SS)
		write(1, "ss\n", 3);
	else if (nod->num == RR)
		write(1, "rr\n", 3);
}

/* It recives a list of instructions and print it */
static void	ft_print_inst(t_nod *nod)
{
	while (nod)
	{
		if (nod->num == SA)
			write(1, "sa\n", 3);
		else if (nod->num == SB)
			write(1, "sb\n", 3);
		else if (nod->num == RA)
			write(1, "ra\n", 3);
		else if (nod->num == RB)
			write(1, "rb\n", 3);
		else if (nod->num == PA)
			write(1, "pa\n", 3);
		else if (nod->num == PB)
			write(1, "pb\n", 3);
		else
			ft_print_inst2(nod);
		nod = nod->next;
	}
}

/* Gives rank to each element in a stack, 1 for the smallest, 2 for next... */
/* Reads a code for elements of stack, choose a different technique for each */
static void	ft_push_swap(t_stack *a_stk, t_stack *b_stk)
{
	int	stk_code;

	ft_number_stack(a_stk);
	if (a_stk->cnt <= 7)
	{
		stk_code = ft_read_code(a_stk->first);
		if (a_stk->cnt <= 3)
			ft_solve_kase3(a_stk, a_stk, stk_code, a_stk->inst);
		if (a_stk->cnt == 4)
			ft_solve_kase4(a_stk, b_stk, stk_code);
		if (a_stk->cnt == 5)
			ft_solve_kase5(a_stk, b_stk);
		if (a_stk->cnt == 6)
			ft_solve_kase6(a_stk, b_stk, stk_code);
		if (a_stk->cnt == 7)
			ft_solve_kase7(a_stk, b_stk, stk_code);
	}
	else
		ft_lis_algorithm(&a_stk, b_stk);
}

/* Initializes two stacks, read arguments, orders a_stack, and print      */
/* instructions, then clear (and free) stacks, flag 'status' will control */
/* error all along the proccess.                                          */
int	main(int argc, char **argv)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	if (argc > 1)
	{
		a_stk = ft_init_stack(_A);
		b_stk = ft_init_stack(_B);
		if (!a_stk || !b_stk)
			ft_error(&a_stk, &b_stk);
		ft_split_args(argv, a_stk);
		if (a_stk->state != GOOD)
			ft_error(&a_stk, &b_stk);
		ft_push_swap(a_stk, b_stk);
		if (a_stk->state == ERROR)
			ft_error(&a_stk, &b_stk);
		ft_print_inst(a_stk->inst);
		ft_clear_stacks(&a_stk, &b_stk);
	}
	return (0);
}
