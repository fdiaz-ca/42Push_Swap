# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:58:38 by fdiaz-ca          #+#    #+#              #
#    Updated: 2022/10/08 02:26:11 by fdiaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libget_next_line.a

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f


all:		$(NAME)

$(NAME):	
		cc -c $(CFLAGS) $(SRCS)
		ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
