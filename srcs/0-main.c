/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 14:38:18 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_input_function(void)
{
	exit(EXIT_FAILURE);
}

void	exit_null_free(void)
{
	exit(EXIT_FAILURE);
}

void element_swap(t_element *a,t_element *b)
{
	t_element tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sa_move(t_stack stack_a)
{
	element_swap(&stack_a.stack[0],&stack_a.stack[1]);
}

void sb_move(t_stack stack_b)
{
	element_swap(&stack_b.stack[0],&stack_b.stack[1]);
}

void ss_move(t_stack stack_a, t_stack stack_b)
{
	element_swap(&stack_a.stack[0],&stack_a.stack[1]);
	element_swap(&stack_b.stack[0],&stack_b.stack[1]);
}

void ra_move(t_stack stack_a)
{
	t_element tmp;

	tmp = stack_a.stack[0];
	ft_memmove(&(stack_a.stack[0]), &(stack_a.stack[1]), (stack_a.size - 1)*sizeof(t_element));
	stack_a.stack[stack_a.size - 1] = tmp;
}

void rb_move(t_stack stack_b)
{
	t_element tmp;

	tmp = stack_b.stack[0];
	ft_memmove(&(stack_b.stack[0]), &(stack_b.stack[1]), (stack_b.size - 1)*sizeof(t_element));
	stack_b.stack[stack_b.size - 1] = tmp;
}

int	main(int argc, char **argv)
{
	char	**args;
	int		*tab;
	int		i;
	int		len;
	int		*tab_dup;
	t_stack	stack_a;
	t_stack stack_b;

	args = argument_analyser(argc, argv);
	tab = numbers_converter(args, &len);
	free_args(args);
	tab_dup = tab_copy(tab, len);
	tab_sort(tab_dup, len);

	stack_a = stack_a_creator(tab, tab_dup, len);
	stack_b = stack_b_creator(len);
	i = 0;
	ft_printf("before\n");
	while (i < len)
	{ 
		ft_printf("%d - %d\n", stack_a.stack[i].nbr, stack_a.stack[i].pos);
		i++;
	}
	ra_move(stack_a);
	ra_move(stack_a);
	ft_printf("\nafter\n");
	i = 0;
	while (i < len)
	{
		ft_printf("%d - %d\n", stack_a.stack[i].nbr, stack_a.stack[i].pos);
		i++;
	}
}

// tab[0] is on the top
//valgrind
//garbage collector system
