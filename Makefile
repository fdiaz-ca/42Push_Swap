# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 20:43:10 by fdiaz-ca          #+#    #+#              #
#    Updated: 2022/10/24 07:27:21 by pakismac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
B_NAME	=	checker

SRCS	=	main.c best_movements.c lis_algorithm_1.c lis_algorithm_2.c\
			lis_algorithm_3.c manage_stacks.c misc_utils_1.c \
			misc_utils_2.c operations_1.c operations_2.c reading_args1.c \
			reading_args2.c solve_kases_1.c solve_kases_2.c \
			solve_kases_3.c solve_kases_4.c \

S_BONUS	=	checker_pak_bonus.c manage_stacks.c operations_1.c \
			operations_2.c reading_args1.c reading_args2.c \

OBJS	=	$(SRCS:.c=.o)
O_BONUS	=	$(S_BONUS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
GNL_DIR	=	./gnl

GRN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

all:	$(NAME)
		
$(NAME):	$(SRCS)	
		@echo "$(YEL)==== Compiling push_swap ====$(EOC)"
		@$(CC) -c $(SRCS) $(CFLAGS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GRN)==== push_swap Compiled ====$(EOC)"

bonus:		$(S_BONUS)
	@echo "$(YEL)==== Building get_next_line ====$(EOC)"
	@make -C $(GNL_DIR) --silent
	@echo "$(GRN)        ==== Done ====         $(EOC)"
	@echo "$(YEL) ==== Compiling checker ====$(EOC)"
	@$(CC) -c $(CFLAGS) $(S_BONUS) -I $(GNL_DIR)
	@$(CC) $(CFLAGS) $(O_BONUS) -L $(GNL_DIR) -lget_next_line -o $(B_NAME)
	@echo "$(GRN)      _==__==_Done_==__==_       $(EOC)"

clean:
		@echo "$(YEL)==== Deleting objects files ====$(EOC)"
		@make -C $(GNL_DIR) clean --silent
		@$(RM) $(OBJS) $(O_BONUS)
		@echo "$(YEL)       ==== Done ====  $(EOC)"

fclean:	clean
		@echo "$(YEL)==== Deleting binary files ====$(EOC)"
		@make -C $(GNL_DIR) fclean --silent
		@$(RM) $(NAME) $(B_NAME)
		@echo "$(YEL)       ==== Done ====  $(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus
