/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:45 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:29:32 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

typedef struct s_element
{
	int			nbr;
	int			pos;
}				t_element;

typedef struct s_stack
{
	t_element	*stack;
	int			size;
}				t_stack;

typedef struct s_stacks
{
	t_stack	sta;
	t_stack	stb;
}				t_stacks;

enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

void			empty_string_checker(int argc, char **argv);
void			check_for_spaces_and_signes(int argc, char **argv);
void			exit_input_function(void);
int				ft_atoi_max(const char *str, int *check);
char			***total_generator(int argc, char **argv);
char			**data_joiner(char ***total, int argc);
char			**check_duplicates(char **final);
void			free_total(char ***total);
int				error_detector(char **argv, int i, int j);
int				*numbers_converter(char **final, int *len);
char			**argument_analyser(int argc, char **argv);
void			exit_null_free(void);
int				max_value_error(int check);
void			free_total_exit(char ***total);
void			free_args(char **args);
int				*tab_copy(int *tab, int len);
int				*tab_sort(int *tab, int len);
t_stack			stack_a_creator(int *tab, int *tab_dup, int len);
t_stack			stack_b_creator(int len);
void			swap(int *a, int *b);
void			move(int nbr, t_stack *stack_a, t_stack *stack_b);
void			sorting_system(t_stack *sta, t_stack *stb);

void			cheking_system(t_stack *sta, t_stack *stb);

void			sa_move(t_stack *stack_a, t_stack *stack_b);
void			sb_move(t_stack *stack_a, t_stack *stack_b);
void			ss_move(t_stack *stack_a, t_stack *stack_b);
void			ra_move(t_stack *stack_a, t_stack *stack_b);
void			rb_move(t_stack *stack_a, t_stack *stack_b);
void			rr_move(t_stack *stack_a, t_stack *stack_b);
void			rra_move(t_stack *stack_a, t_stack *stack_b);
void			rrb_move(t_stack *stack_a, t_stack *stack_b);
void			rrr_move(t_stack *stack_a, t_stack *stack_b);
void			pb_move(t_stack *stack_a, t_stack *stack_b);
void			pa_move(t_stack *stack_a, t_stack *stack_b);
void			send_to_stb(t_stack *sta, t_stack *stb, int len, int range);
void			back_to_sta(t_stack *sta, t_stack *stb, int max);

#endif