/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-stack_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:46:31 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 18:32:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



////////segfault shit
void element_swap(t_element *a,t_element *b)
{
	t_element tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sa_move(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	element_swap(&stack_a->stack[0],&stack_a->stack[1]);
}

void sb_move(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	element_swap(&stack_b->stack[0],&stack_b->stack[1]);
}

void ss_move(t_stack *stack_a, t_stack *stack_b)
{
	element_swap(&stack_a->stack[0],&stack_a->stack[1]);
	element_swap(&stack_b->stack[0],&stack_b->stack[1]);
}

void ra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_b;
	tmp = stack_a->stack[0];
	ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)*sizeof(t_element));
	stack_a->stack[stack_a->size - 1] = tmp;
}

void rb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_a;
	tmp = stack_b->stack[0];
	ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[stack_b->size - 1] = tmp;
}

void rr_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	tmp = stack_a->stack[0];
	ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)*sizeof(t_element));
	stack_a->stack[stack_a->size - 1] = tmp;
	tmp = stack_b->stack[0];
	ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[stack_b->size - 1] = tmp;
}

void rra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_b;
	tmp = stack_a->stack[stack_a->size - 1];
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size - 1)*sizeof(t_element));
	stack_a->stack[0] = tmp;
}

void rrb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_a;
	tmp = stack_b->stack[stack_b->size - 1];
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[0] = tmp;
}

void rrr_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	tmp = stack_a->stack[stack_a->size - 1];
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size - 1)*sizeof(t_element));
	stack_a->stack[0] = tmp;
	tmp = stack_b->stack[stack_b->size - 1];
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[0] = tmp;
}

void pb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;
	if (stack_a->size == 0)
	{
		exit(1);
	}
	tmp = stack_a->stack[0];
	ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)*sizeof(t_element));
	(stack_a->size)--;
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size)*sizeof(t_element));
	stack_b->stack[0] = tmp;
	stack_b->size++;
}

void pa_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;
	if (stack_b->size == 0)
	{
		exit(1);
	}
	tmp = stack_b->stack[0];
	ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)*sizeof(t_element));
	(stack_b->size)--;
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size)*sizeof(t_element));
	stack_a->stack[0] = tmp;
	stack_a->size++;
}

void move(int nbr,t_stack *stack_a, t_stack *stack_b)
{
	void (*action[11])(t_stack *, t_stack *);

    action[sa]=sa_move;
    action[sb]=sb_move;
    action[ss]=ss_move;
    action[pa]=pa_move;
    action[pb]=pb_move;
    action[ra]=ra_move;
    action[rb]=rb_move;
    action[rr]=rr_move;
    action[rra]=rra_move;
    action[rrb]=rrb_move;
    action[rrr]=rrr_move;
	(*action[nbr])(stack_a,stack_b);
}