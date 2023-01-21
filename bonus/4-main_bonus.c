/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:28:22 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 19:39:19 by mkhellou         ###   ########.fr       */
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
	cheking_system(&stack_a,&stack_b);
}