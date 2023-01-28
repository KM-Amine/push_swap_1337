/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stack_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:20:27 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 15:49:08 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	element_swap(t_element *a, t_element *b)
{
	t_element	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa_move(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size != 1 && stack_a->size != 0)
		element_swap(&stack_a->stack[0], &stack_a->stack[1]);
}

void	sb_move(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	if (stack_b->size != 1 && stack_b->size != 0)
		element_swap(&stack_b->stack[0], &stack_b->stack[1]);
}

void	ss_move(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 1 && stack_a->size != 0)
		element_swap(&stack_a->stack[0], &stack_a->stack[1]);
	if (stack_b->size != 1 && stack_b->size != 0)
		element_swap(&stack_b->stack[0], &stack_b->stack[1]);
}

void	ra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	(void)stack_b;
	if (stack_a->size != 1 && stack_a->size != 0)
	{
		tmp = stack_a->stack[0];
		ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size
				- 1) * sizeof(t_element));
		stack_a->stack[stack_a->size - 1] = tmp;
	}
}
