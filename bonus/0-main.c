/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 17:09:15 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//norm 
//leaks
//leaks in invalid input
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
	cheking_system(&(stacks.sta), &(stacks.stb));
	free(stacks.sta.stack);
	free(stacks.stb.stack);
	return (0);
}
