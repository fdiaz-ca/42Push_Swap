/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:32:02 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 20:30:26 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* It finds and return the position of element of stack */
/* corresponding to the rank or number passed on key */
int	ft_get_index(t_stack *stk, int num, int key)
{
	t_nod	*tmp;
	int		cnt;
	int		finded;

	finded = 0;
	tmp = stk->first;
	cnt = 0;
	while (!finded && tmp)
	{
		if (key == RANK && tmp->rank == num)
			finded = 1;
		if (key == NUM && tmp->num == num)
			finded = 1;
		cnt++;
		tmp = tmp->next;
	}
	return (cnt * finded);
}

/* It finds the rank of a number in a given stack */
static int	ft_find_rank(t_stack *stk, int num)
{
	t_nod	*tmp;
	int		cnt;

	tmp = stk->first;
	cnt = 1;
	while (tmp)
	{
		if (tmp->num < num)
			cnt += 1;
		tmp = tmp->next;
	}
	return (cnt);
}

/* It find the rank in a stack for every number in it */
void	ft_number_stack(t_stack *stk)
{
	t_nod	*tmp;

	tmp = stk->first;
	while (tmp)
	{
		tmp->rank = ft_find_rank(stk, tmp->num);
		tmp = tmp->next;
	}
}

/* It creates a node with num value, and put it at the end of list */
void	ft_create_last(t_stack *stk, int num)
{
	t_nod	*tmp;

	tmp = (t_nod *)malloc(sizeof(t_nod));
	if (!tmp)
	{
		stk->state = ERROR;
		return ;
	}
	tmp->rank = 0;
	tmp->num = num;
	tmp->next = NULL;
	if (!stk->last)
	{
		stk->first = tmp;
		tmp->prev = NULL;
	}
	else
	{
		tmp->prev = stk->last;
		stk->last->next = tmp;
	}
	stk->last = tmp;
	stk->cnt += 1;
}

/* Travel a stack, return 1 if num is not on the stack, 0 otherwise */
/* to check that there is no repeated number on stack               */
int	ft_not_here(t_stack *stk, int num)
{
	t_nod	*tmp;

	if (stk->state != ERROR)
	{
		tmp = stk->first;
		while (tmp)
		{
			if (tmp->num == num)
			{
				stk->state = ERROR;
				return (0);
			}
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}
