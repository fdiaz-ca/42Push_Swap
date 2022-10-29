/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakismac <pakismac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:26:37 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/10/24 06:14:56 by pakismac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# define INTOP -2
# define INBOT -1
# define GOOD 1
# define MULTI 2
# define ERROR 3
# define NUM 4
# define SIGN 5
# define SPC 6
# define _A 7
# define _B 8
# define COPY 9
# define RANK 11
# define COMMON 13
# define UNCOMM 14
# define PA 21
# define PB 22
# define SA 23
# define SB 24
# define SS 25
# define RA 26
# define RB 27
# define RR 28
# define RRA 29
# define RRB 30
# define RRR 31

typedef struct s_nod
{
	int				num;
	int				rank;
	struct s_nod	*next;
	struct s_nod	*prev;

}					t_nod;

typedef struct s_lis
{
	int				num;
	int				rank;
	struct s_lis	*next;
	struct s_lis	*prox;
	struct s_lis	*prev;
}					t_lis;

typedef struct s_stack
{
	int				cnt;
	int				state;
	int				name;
	struct s_nod	*first;
	struct s_nod	*last;
	struct s_nod	*inst;

}					t_stack;

int		ft_abs(int num);
void	*ft_calloc(size_t count, size_t size);
void	ft_number_stack(t_stack *stk);
int		ft_get_index(t_stack *stk, int num, int key);
void	ft_clear_list(t_nod **nod);
void	ft_clear_lis(t_lis **lis);
void	ft_clear_stacks(t_stack **a_stck, t_stack **b_stck);
void	ft_error(t_stack **a_stck, t_stack **b_stck);
t_stack	*ft_init_stack(int name);
void	ft_add_inst(t_stack *a_stk, t_nod *ins, int inst);
void	ft_add_nod(t_stack *stk, int place, t_nod *nod);
t_nod	*ft_rem_nod(t_stack *stk, int place);
void	ft_swap(t_stack *a_stk, t_stack *stk, t_nod *ins);
void	ft_s_swap(t_stack *a_stk, t_stack *b_stk, t_nod *ins);
void	ft_push(t_stack *a_stk, t_stack *pri, t_stack *sec, t_nod *ins);
void	ft_rev_rotate(t_stack *a_stk, t_stack *stk, t_nod *ins);
void	ft_r_rev_rotate(t_stack *a_stk, t_stack *b_stk, t_nod *ins);
void	ft_rotate(t_stack *a_stk, t_stack *stk, t_nod *ins);
void	ft_r_rotate(t_stack *a_stk, t_stack *b_stk, t_nod *ins);
void	ft_create_last(t_stack *stk, int num);
int		ft_not_here(t_stack *stk, int num);
void	ft_split_args(char **str, t_stack *stk);
int		ft_read_code(t_nod *nod);
void	ft_solve_kase4(t_stack *a_stk, t_stack *b_stk, int code);
void	ft_solve_kase3(t_stack *a_stk, t_stack *stk, int k, t_nod *ins);
void	ft_remove_min(t_stack *a_stk, t_stack *stk, int rep);
int		ft_copy_stks(t_stack *a, t_stack *b, t_stack **a_cpy, t_stack **b_cpy);
void	ft_solve_kase5_1(t_stack *a_stk, t_stack *b_stk);
void	ft_add_inst_list(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b);
void	ft_optimize_code_change(t_nod *tmp_a, t_nod *tmp_b);
void	ft_optimize_code6(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b);
void	ft_solve_kase6_1(t_stack *a_stk, t_stack *b_stk, int code_a);
void	ft_optimize_code7_change(t_nod *tmp_a, t_nod *ins_b);
void	ft_optimize_code7(t_stack *a_stk, t_nod *ins_a, t_nod *ins_b);
void	ft_solve_kase7_1(t_stack *a_stk, t_stack *b_stk, int code_a);
int		ft_bestway_top(t_stack *a_stk, int num, int key);
int		ft_get_next_rank(t_stack *stk, int rank);
t_nod	*ft_best_move(t_stack *b_stk, t_stack *a_stk);
void	ft_move_uncommons(t_stack *a_stk, t_stack *b_stk, t_stack *lis);
void	ft_best_movements(t_stack *a_stk, t_stack *b_stk);
t_stack	*ft_copy_stack(t_stack *stk, int name);
void	ft_min_to_the_top(t_stack *a_stk, t_stack *stk, t_nod *ins);
t_lis	*ft_lis1(t_lis *lis);
t_lis	*ft_lis2(t_lis *lis);
t_stack	*ft_get_lis1(t_stack *a_stk);
t_stack	*ft_get_lis2(t_stack *a_stk);
void	ft_lis_algorithm(t_stack **a_stk, t_stack *b_stk);
void	ft_solve_kase7(t_stack *a_stk, t_stack *b_stk, int code_a);
void	ft_solve_kase6(t_stack *a_stk, t_stack *b_stk, int code_a);
void	ft_solve_kase5(t_stack *a_stk, t_stack *b_stk);

#endif
