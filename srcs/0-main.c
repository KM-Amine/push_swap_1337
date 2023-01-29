/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/29 14:57:56 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *sta)
{
	int	i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i + 1].pos)
			return (0);
		i++;
	}
	return (1);
}

void	sorted_check(t_stack *sta, t_stack *stb)
{
	if (sta->size == 1 && stb->size == 0)
		exit(EXIT_SUCCESS);
	if (is_sorted(sta) && stb->size == 0)
		exit(EXIT_SUCCESS);
}

//general instruction
//tableau d'info
//norminette
//gnl bonus
//tester for bonus and other stuff
//submition and per-per evaluation
//norm
//leaks

int	main(int argc, char **argv)
{
	char		**args;
	int			*tab;
	int			len;
	int			*tab_dup;
	t_stacks	stacks;

	args = argument_analyser(argc, argv);
	tab = numbers_converter(args, &len);
	free_args(args);
	tab_dup = tab_copy(tab, len);
	tab_sort(tab_dup, len);
	stacks.sta = stack_a_creator(tab, tab_dup, len);
	free(tab);
	free(tab_dup);
	stacks.stb = stack_b_creator(len);
	if (!stacks.stb.stack)
	{
		free(stacks.sta.stack);
		exit(EXIT_FAILURE);
	}
	sorted_check(&(stacks.sta), &(stacks.stb));
	sorting_system(&(stacks.sta), &(stacks.stb));
	free(stacks.sta.stack);
	free(stacks.stb.stack);
	return (0);
}
