/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_args1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:26:15 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 20:28:22 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* It checks if c is valid num, space or sign, depending on ctrl value */
static int	ft_valid(int ctrl, char c)
{
	if (ctrl == NUM)
	{
		if ((c >= '0') && (c <= '9'))
			return (GOOD);
	}
	else if (ctrl == SPC)
	{
		if (((c >= 9) && (c <= 13)) || (c) == ' ')
			return (GOOD);
	}
	else if (ctrl == SIGN)
	{
		if ((c == '+') || (c == '-'))
			return (GOOD);
	}
	return (0);
}

/* It checks and, if needed, changes de value of sign */
static void	ft_get_sign(char **str, int *sign)
{
	if (ft_valid(SIGN, **str))
	{
		if (**str == '-')
			*sign = -1;
		*str += 1;
	}
}

/* Classical atoi and checks if number is in range */
/* multi is for '1 2 "4 5 " 6' kind of argunments  */
static int	ft_atoi_check(t_stack *stk, char **str)
{
	long int		num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_valid(SPC, **str))
		*str += 1;
	ft_get_sign(str, &sign);
	while (ft_valid(NUM, **str))
	{
		num = (num * 10) + (**str - '0');
		*str += 1;
	}
	num = num * sign;
	if ((num < INT_MIN) || (num > INT_MAX))
	{
		stk->state = ERROR;
		return (0);
	}
	if (ft_valid(SPC, **str))
		stk->state = MULTI;
	else
		stk->state = GOOD;
	return ((int)(num));
}

/* It checks if char is a valid number, space or sign, and              */
/* return error if there's a sign after a number, or two signs together */
static int	ft_str_check(char *s)
{
	int	with_num;

	with_num = 0;
	while (*s)
	{
		if (ft_valid(SPC, *s) || ft_valid(NUM, *s) || ft_valid(SIGN, *s))
		{
			if (ft_valid(NUM, *s))
				with_num = GOOD;
			if ((ft_valid(NUM, *s) && ft_valid(SIGN, *(s + 1)))
				|| (ft_valid(SIGN, *s) && ft_valid(SIGN, *(s + 1))))
				return (ERROR);
		}
		else
			return (ERROR);
		s += 1;
	}
	return (with_num);
}

/* It reads chars of str argument, and check for errors. If no error */
/* it adds the number at the end of stack                            */
void	ft_split_args(char **str, t_stack *stk)
{
	int	num;

	str += 1;
	while ((*str) && (stk->state == GOOD))
	{
		stk->state = ft_str_check(*str);
		if (stk->state != GOOD)
			return ;
		num = ft_atoi_check(stk, str);
		if (ft_not_here(stk, num))
			ft_create_last(stk, num);
		while ((stk->state == MULTI) && ft_str_check(*str))
		{
			num = ft_atoi_check(stk, str);
			if (ft_not_here(stk, num))
				ft_create_last(stk, num);
		}
		if ((stk->state == MULTI) && !ft_str_check(*str))
			stk->state = GOOD;
		str += 1;
	}		
}
