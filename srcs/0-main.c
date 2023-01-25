/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/25 16:24:37 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int					ft_printf(const char *str, ...);


// void stacks_printer(t_stack *stack_a, t_stack *stack_b)
// {
// 	int i ;

// 	i = 0;
// 	while (i < stack_a->size)
// 	{ 
// 		ft_printf("%d - %d\n", stack_a->stack[i].nbr, stack_a->stack[i].pos);
// 		i++;
// 	}
// 	ft_printf("-------------------\n");
// 	i = 0;
// 	while (i < stack_b->size)
// 	{ 
// 		ft_printf("%d - %d\n", stack_b->stack[i].nbr, stack_b->stack[i].pos);
// 		i++;
// 	}
// 	ft_printf("-------------------\n");
// }

void	exit_input_function(void)
{
	exit(EXIT_FAILURE);
}

void	exit_null_free(void)
{
	exit(EXIT_FAILURE);
}

int is_sorted(t_stack *sta)
{
	int i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i+1].pos)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void sorted_check(t_stack *sta)
{
	if (sta->size == 1)
		exit(0);
	if (is_sorted(sta))
		exit(0);
}

// stack like a real stack
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
	sorted_check(&stack_a);
	sorting_system(&stack_a,&stack_b);
}
// string like " " "+ " "- "
// tab[0] is on the top
//valgrind
//garbage collector system
// duplicate numbers of atoi