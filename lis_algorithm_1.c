/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:13:28 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 04:46:19 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lis	*ft_init_lis(int num)
{
	t_lis	*tmp;

	tmp = malloc(sizeof(t_lis));
	if (!tmp)
		return (NULL);
	tmp->num = num;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->prox = NULL;
	tmp->rank = 1;
	return (tmp);
}

static t_lis	*ft_stack_to_lis(t_stack *aux)
{
	t_lis	*lis;
	t_lis	*tmp_lis;
	t_nod	*tmp_nod;

	tmp_nod = aux->first;
	lis = ft_init_lis(tmp_nod->num);
	if (!lis)
		return (NULL);
	tmp_lis = lis;
	while (tmp_nod->next)
	{
		tmp_lis->prox = ft_init_lis(tmp_nod->next->num);
		if (!tmp_lis->prox)
		{
			ft_clear_lis(&lis);
			return (NULL);
		}
		tmp_lis->prox->prev = tmp_lis;
		tmp_lis = tmp_lis->prox;
		tmp_nod = tmp_nod->next;
	}
	return (lis);
}

static void	ft_lis_to_stack(t_stack *stk, t_lis *best)
{
	ft_clear_list(&(stk->first));
	stk->cnt = 0;
	stk->last = NULL;
	while (best)
	{
		ft_create_last(stk, best->num);
		if (stk->state == ERROR)
			return ;
		best = best->next;
	}
}

t_stack	*ft_get_lis1(t_stack *a_stk)
{
	t_stack	*aux;
	t_lis	*best;
	t_lis	*lis;

	aux = ft_copy_stack(a_stk, COPY);
	if (!aux)
		return (NULL);
	ft_min_to_the_top(a_stk, aux, NULL);
	lis = ft_stack_to_lis(aux);
	if (!lis || aux->state == ERROR)
	{
		ft_clear_lis(&lis);
		ft_clear_stacks(&aux, NULL);
		return (NULL);
	}
	best = ft_lis1(lis);
	ft_lis_to_stack(aux, best);
	if (aux->state == ERROR)
	{
		ft_clear_stacks(&aux, NULL);
		aux = NULL;
	}
	ft_clear_lis(&lis);
	return (aux);
}

t_stack	*ft_get_lis2(t_stack *a_stk)
{
	t_stack	*aux;
	t_lis	*best;
	t_lis	*lis;

	aux = ft_copy_stack(a_stk, COPY);
	if (!aux)
		return (NULL);
	ft_min_to_the_top(a_stk, aux, NULL);
	lis = ft_stack_to_lis(aux);
	if (!lis || aux->state == ERROR)
	{
		ft_clear_lis(&lis);
		ft_clear_stacks(&aux, NULL);
		return (NULL);
	}
	best = ft_lis2(lis);
	ft_lis_to_stack(aux, best);
	if (aux->state == ERROR)
	{
		ft_clear_stacks(&aux, NULL);
		aux = NULL;
	}
	ft_clear_lis(&lis);
	return (aux);
}
