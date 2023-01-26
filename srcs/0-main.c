/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/26 18:20:05 by mkhellou         ###   ########.fr       */
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

int is_sorted(t_stack *sta)
{
	int i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i+1].pos)
			return (0);
		i++;
	}
	return (1);
}

void sorted_check(t_stack *sta,t_stack *stb)
{
	if (sta->size == 1 && stb->size == 0)
		exit(0);
	if (is_sorted(sta))
		exit(0);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		*tab;
	int		len;
	int		*tab_dup;
	t_stack	stack_a;
	t_stack stack_b;
	
	(void)argc;
	(void)argv;
	args = argument_analyser(argc, argv);
	tab = numbers_converter(args, &len);
	free_args(args);
	tab_dup = tab_copy(tab, len);
	tab_sort(tab_dup, len);
	stack_a = stack_a_creator(tab, tab_dup, len);
	stack_b = stack_b_creator(len);
	sorted_check(&stack_a,&stack_b);
	sorting_system(&stack_a,&stack_b);
}

//valgrind
//garbage collector system
