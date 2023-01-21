/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:45 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 10:18:45 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

typedef struct s_element
{
	int nbr;
	int pos;
} t_element;

typedef struct s_stack
{
	t_element *stack;
	int size;
} t_stack;

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

void	exit_input_function(void);
int		ft_atoi_max(const char *str, int *check);
char	***total_generator(int argc, char **argv);
char	**data_joiner(char ***total, int argc);
char	**check_duplicates(char **final);
void	free_total(char ***total);
void	error_detector(char **argv, int i, int j);
int		*numbers_converter(char **final,int *len);
char	**argument_analyser(int argc, char **argv);
void 	exit_null_free(void);
void	max_value_error(int check);
void	free_total_exit(char ***total);
void	free_args(char **args);
int		*tab_copy(int *tab, int len);
int		*tab_sort(int *tab, int len);
t_stack	stack_a_creator(int *tab, int *tab_dup, int len);
t_stack stack_b_creator(int len);
void swap(int *a, int *b);
void move(int nbr,t_stack *stack_a, t_stack *stack_b);
void	sorting_system(t_stack *sta, t_stack *stb);


void cheking_system(t_stack *sta, t_stack *stb);

#endif