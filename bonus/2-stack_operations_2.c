/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stack_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:19:03 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 15:49:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	(void)stack_a;
	if (stack_b->size != 1 && stack_b->size != 0)
	{
		tmp = stack_b->stack[0];
		ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size
				- 1) * sizeof(t_element));
		stack_b->stack[stack_b->size - 1] = tmp;
	}
}

void	rr_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	if (stack_a->size != 1 && stack_a->size != 0)
	{
		tmp = stack_a->stack[0];
		ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size
				- 1) * sizeof(t_element));
		stack_a->stack[stack_a->size - 1] = tmp;
	}
	if (stack_b->size != 1 && stack_b->size != 0)
	{
		tmp = stack_b->stack[0];
		ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size
				- 1) * sizeof(t_element));
		stack_b->stack[stack_b->size - 1] = tmp;
	}
}

void	rra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	(void)stack_b;
	if (stack_a->size != 1 && stack_a->size != 0)
	{
		tmp = stack_a->stack[stack_a->size - 1];
		ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size
				- 1) * sizeof(t_element));
		stack_a->stack[0] = tmp;
	}
}

void	rrb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	(void)stack_a;
	if (stack_b->size != 1 && stack_b->size != 0)
	{
		tmp = stack_b->stack[stack_b->size - 1];
		ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size
				- 1) * sizeof(t_element));
		stack_b->stack[0] = tmp;
	}
}

void	rrr_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	if (stack_a->size != 1 && stack_a->size != 0)
	{
		tmp = stack_a->stack[stack_a->size - 1];
		ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size
				- 1) * sizeof(t_element));
		stack_a->stack[0] = tmp;
	}
	if (stack_b->size != 1 && stack_b->size != 0)
	{
		tmp = stack_b->stack[stack_b->size - 1];
		ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size
				- 1) * sizeof(t_element));
		stack_b->stack[0] = tmp;
	}
}
