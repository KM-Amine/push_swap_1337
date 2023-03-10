/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stack_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:11:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:17:05 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sta_null_check(int *tab, int *tab_dup, t_stack stack_a)
{
	if (stack_a.stack == NULL)
	{
		free(tab);
		free(tab_dup);
		exit(EXIT_FAILURE);
	}
}

t_stack	stack_a_creator(int *tab, int *tab_dup, int len)
{
	t_stack	stack_a;
	int		i;
	int		j;

	stack_a.stack = (t_element *)ft_calloc(len, sizeof(t_stack));
	sta_null_check(tab, tab_dup, stack_a);
	stack_a.size = len;
	i = -1;
	while (++i < len)
		stack_a.stack[i].nbr = tab[i];
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab_dup[j])
				stack_a.stack[i].pos = j;
			j++;
		}
		i++;
	}
	return (stack_a);
}

t_stack	stack_b_creator(int len)
{
	t_stack	stack_b;

	stack_b.stack = (t_element *)ft_calloc(len, sizeof(t_stack));
	if (!stack_b.stack)
		return (stack_b);
	stack_b.size = 0;
	return (stack_b);
}
