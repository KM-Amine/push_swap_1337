/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/27 21:38:46 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		exit(EXIT_SUCCESS);
	if (is_sorted(sta) && stb->size == 0)
		exit(EXIT_SUCCESS);
}

//bonus sorting sorted_check()
//leaks
//norminette
//gnl bonus
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
	free(tab);
	free(tab_dup);
	stack_b = stack_b_creator(len);
	if(!stack_b.stack)
	{
		free(stack_a.stack);
		exit(EXIT_FAILURE);
	}
	sorted_check(&stack_a,&stack_b);
	sorting_system(&stack_a,&stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
	return(0);
}
