/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:55:00 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/08 02:14:08 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GOOD 1
# define END_F 2
# define LEAVE 3

typedef struct s_list
{
	char			let;
	struct s_list	*next;

}					t_list;

typedef struct s_head
{
	int				n_num;
	char			state;
	struct s_list	*next;

}					t_head;

int					ft_manage_head(t_head **head, int state);
void				ft_take_out(t_head *head, t_list **nod, char *cad);
void				ft_take_in(t_head *head, t_list **next, char *cad);
char				*get_next_line(int fd);
char				*ft_calloc2(int count, int size);
void				ft_read_and_save(t_head *head, int fd);
int					ft_next_line_length(t_head *head);

#endif
