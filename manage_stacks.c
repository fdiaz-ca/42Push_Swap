/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:34:07 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/07 21:42:48 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Walk through the list, doing free on each element  */
void	ft_clear_list(t_nod **nod)
{
	t_nod	*tmp;

	while ((*nod))
	{
		tmp = (*nod);
		(*nod) = (*nod)->next;
		free(tmp);
	}
}

/* Walk through the lis structure, doing free on each element  */
void	ft_clear_lis(t_lis **lis)
{
	t_lis	*tmp;

	while (*lis)
	{
		tmp = (*lis);
		(*lis) = (*lis)->prox;
		free(tmp);
	}
}

/* It takes one/two stacks, clear and free the lists inside, then the stack */
void	ft_clear_stacks(t_stack **a_stck, t_stack **b_stck)
{
	if (a_stck)
	{
		ft_clear_list(&((*a_stck)->inst));
		ft_clear_list(&((*a_stck)->first));
		free(*a_stck);
		*a_stck = NULL;
	}
	if (b_stck)
	{
		ft_clear_list(&((*b_stck)->inst));
		ft_clear_list(&((*b_stck)->first));
		free(*b_stck);
		*b_stck = NULL;
	}
}

/* It clears and frees stacks, print error, and terminates execution */
void	ft_error(t_stack **a_stck, t_stack **b_stck)
{
	ft_clear_stacks(a_stck, b_stck);
	write(1, "Error\n", 6);
	exit(0);
}

/* Initialize a stack, and its instruction list, and first node */
t_stack	*ft_init_stack(int name)
{
	t_stack	*stk;

	stk = (t_stack *)malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->inst = (t_nod *)malloc(sizeof(t_nod));
	if (!(stk->inst))
	{
		free(stk);
		return (NULL);
	}
	stk->inst->next = NULL;
	stk->inst->num = GOOD;
	stk->inst->rank = 0;
	stk->first = NULL;
	stk->last = NULL;
	stk->state = GOOD;
	stk->name = name;
	stk->cnt = 0;
	return (stk);
}
