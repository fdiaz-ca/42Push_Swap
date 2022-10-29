/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pak_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:14:03 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 07:21:04 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

/* Translates instructions in string 's' and checks if they are correct */
int	ft_get_inst(char *s, int i)
{
	if (i == 3 && s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (SA);
	if (i == 3 && s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		return (SB);
	if (i == 3 && s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (SS);
	if (i == 3 && s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (PA);
	if (i == 3 && s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (PB);
	if (i == 3 && s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (RA);
	if (i == 3 && s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (RB);
	if (i == 3 && s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (RR);
	if (i == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		return (RRA);
	if (i == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		return (RRB);
	if (i == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		return (RRR);
	else
		return (ERROR);
}

/* Reads the instructions and stores them in the list 'inst' of the stack a */
void	ft_read_ins(t_stack *a_stk, t_stack *b_stck)
{
	char	*cad;
	int		inst;
	int		i;

	cad = get_next_line(0);
	while (cad)
	{
		i = 0;
		while (cad[i] != '\0')
			i++;
		inst = ft_get_inst(cad, i);
		free(cad);
		if (inst == ERROR)
			a_stk->state = ERROR;
		if (a_stk->state != ERROR)
			ft_add_inst(a_stk, a_stk->inst, inst);
		cad = get_next_line(0);
	}
	if (a_stk->state == ERROR)
		ft_error(&a_stk, &b_stck);
}

/* Execute the list of instructions 'ins' on the stack a */
void	ft_exec_inst(t_stack *a_stk, t_stack *b_stk, int ins)
{
	if (ins == SA)
		ft_swap(a_stk, a_stk, NULL);
	else if (ins == SB)
		ft_swap(a_stk, b_stk, NULL);
	else if (ins == SS)
		ft_s_swap(a_stk, b_stk, NULL);
	else if (ins == PA)
		ft_push(a_stk, a_stk, b_stk, NULL);
	else if (ins == PB)
		ft_push(a_stk, b_stk, a_stk, NULL);
	else if (ins == RA)
		ft_rotate(a_stk, a_stk, NULL);
	else if (ins == RB)
		ft_rotate(a_stk, b_stk, NULL);
	else if (ins == RR)
		ft_r_rotate(a_stk, b_stk, NULL);
	else if (ins == RRA)
		ft_rev_rotate(a_stk, a_stk, NULL);
	else if (ins == RRB)
		ft_rev_rotate(a_stk, b_stk, NULL);
	else if (ins == RRR)
		ft_r_rev_rotate(a_stk, b_stk, NULL);
}

/* Check that stack a is sorted and that stack b is empty */
void	ft_check_stacks(t_stack *a_stk, t_stack *b_stk)
{
	t_nod	*tmp;
	int		prev_num;

	tmp = a_stk->first;
	prev_num = tmp->num;
	while (tmp->next && (tmp->next->num > prev_num))
	{
		prev_num = tmp->next->num;
		tmp = tmp->next;
	}
	if (!tmp->next && b_stk->cnt == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/* initializes stacks, reads arguments, reads instructions,    */
/* applies them to the stack, and checks that they are correct */
int	main(int argc, char **argv)
{
	t_stack	*a_stk;
	t_stack	*b_stk;
	t_nod	*inst;

	if (argc > 1)
	{
		a_stk = ft_init_stack(_A);
		b_stk = ft_init_stack(_B);
		if (!a_stk || !b_stk)
			ft_error(&a_stk, &b_stk);
		ft_split_args(argv, a_stk);
		if (a_stk->state != GOOD)
			ft_error(&a_stk, &b_stk);
		ft_read_ins(a_stk, b_stk);
		inst = a_stk->inst->next;
		while (inst)
		{
			ft_exec_inst(a_stk, b_stk, inst->num);
			inst = inst->next;
		}
		ft_check_stacks(a_stk, b_stk);
		ft_clear_stacks(&a_stk, &b_stk);
	}
	return (0);
}
