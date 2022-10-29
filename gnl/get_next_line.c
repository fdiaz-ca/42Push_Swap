/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:26:22 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/08 02:30:32 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Recursively, it will create a node and store a char in it, for each char  */
/* in the string 'cad'. Any time a char is '\n', head->n_num will increase   */
/* First condition gets (*next) at the end of structure.                     */
void	ft_take_in(t_head *head, t_list **next, char *cad)
{
	if ((head->state != LEAVE) && (*next) && (cad[0]))
		ft_take_in(head, &((*next)->next), cad);
	else if ((head->state != LEAVE) && (!(*next) && (cad[0])))
	{
		*next = malloc(sizeof(t_list));
		if (!(*next))
		{
			head->state = LEAVE;
			return ;
		}
		(*next)->next = NULL;
		(*next)->let = cad[0];
		if (cad[0] == '\n')
			head->n_num += 1;
		if (cad[1])
			ft_take_in(head, &((*next)->next), cad + 1);
	}
}

/* Recursively, it will take_out a node and store the char in it in 'cad' in */
/* its position in the string. The nod taken out, will be deallocated in mem.*/
void	ft_take_out(t_head *head, t_list **nod, char *cad)
{
	t_list	*tmp;

	if (*nod)
	{
		cad[0] = (*nod)->let;
		if ((cad[0] != '\n') && (*nod)->next)
			ft_take_out(head, &((*nod)->next), cad + 1);
		else if (cad[0] == '\n')
			head->n_num -= 1;
		tmp = *nod;
		*nod = (*nod)->next;
		free(tmp);
	}
}

/* It prepares 'buffer' to read from file, as many chars as BUFFER_SIZE. In  */
/* case of memory failure 'head->state' is set to LEAVE, and interrupts the  */
/* process. If there is nothing to read 'head->state' flag is set to END_F.  */
/* If all went GOOD, then it will 'take_in' buffer into head structure.      */
void	ft_read_and_save(t_head *head, int fd)
{
	char	*buffer;
	int		ctrl;

	buffer = ft_calloc2(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
	{
		head->state = LEAVE;
		return ;
	}
	ctrl = read(fd, buffer, BUFFER_SIZE);
	if ((ctrl == -1) || (!ctrl && !buffer[0]))
		head->state = END_F;
	else
		ft_take_in(head, &(head->next), buffer);
	free(buffer);
}

/* Function initializes 'head'. Mem_check and head->state will take LEAVE    */
/* in case of memory failure, in which case it'll clean and free the whole   */
/* structure and return NULL. It will read_and_save from file, until '\n'    */
/* appears (increasing head->n_num) or end of file (head->state = END_F).    */
/* Then it prepares 'next_line' to take_out next line in structure, and      */
/* return it.                                                                */
char	*get_next_line(int fd)
{
	static t_head	*head;
	char			*next_line;
	int				mem_check;

	mem_check = GOOD;
	if (!head)
		mem_check = ft_manage_head(&head, GOOD);
	while ((mem_check == GOOD) && (head->n_num == 0) && (head->state == GOOD))
		ft_read_and_save(head, fd);
	if ((mem_check == LEAVE) || (head->state == LEAVE)
		|| (head->state == END_F && !(head->next)))
	{
		ft_manage_head(&head, LEAVE);
		return (NULL);
	}
	next_line = ft_calloc2(sizeof(char), (ft_next_line_length(head) + 1));
	if (!next_line)
		ft_manage_head(&head, LEAVE);
	else
		ft_take_out(head, &(head->next), next_line);
	return (next_line);
}
