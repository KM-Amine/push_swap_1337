/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-stack_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:45:48 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 09:45:50 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

t_stack	stack_a_creator(int *tab, int *tab_dup, int len)
{
	t_stack stack_a;
	int i;
	int j;

	stack_a.stack  = (t_element *)ft_calloc(len, sizeof(t_stack));
	stack_a.size = len;
	i = 0;
	while (i < len)
	{
		stack_a.stack[i].nbr = tab[i];
		i++;
	}
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

t_stack stack_b_creator(int len)
{
	t_stack stack_b;

	stack_b.stack  = (t_element *)ft_calloc(len, sizeof(t_stack));
	stack_b.size = 0;
	return (stack_b);
}
