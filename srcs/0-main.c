/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 16:23:49 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void stacks_printer(t_stack *stack_a, t_stack *stack_b)
{
	int i ;

	i = 0;
	while (i < stack_a->size)
	{ 
		ft_printf("%d - %d\n", stack_a->stack[i].nbr, stack_a->stack[i].pos);
		i++;
	}
	ft_printf("-------------------\n");
	i = 0;
	while (i < stack_b->size)
	{ 
		ft_printf("%d - %d\n", stack_b->stack[i].nbr, stack_b->stack[i].pos);
		i++;
	}
	ft_printf("-------------------\n");
}

void	exit_input_function(void)
{
	exit(EXIT_FAILURE);
}

void	exit_null_free(void)
{
	exit(EXIT_FAILURE);
}

//array of pointer to function
int	main(int argc, char **argv)
{
	char	**args;
	int		*tab;
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
	sorting_system(&stack_a,&stack_b);
}
// tab[0] is on the top
//valgrind
//garbage collector system
