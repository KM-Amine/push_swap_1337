/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stack_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:20:27 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/26 19:06:28 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//segfault and other shit

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
	if (stack_a->size != 1 && stack_a->size != 0)
		element_swap(&stack_a->stack[0],&stack_a->stack[1]);
	ft_printf("sa\n");
}

void sb_move(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	if (stack_b->size != 1 && stack_b->size != 0)
		element_swap(&stack_b->stack[0],&stack_b->stack[1]);
	ft_printf("sb\n");
}

void ss_move(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 1 && stack_a->size != 0)
		element_swap(&stack_a->stack[0],&stack_a->stack[1]);
	if (stack_b->size != 1 && stack_b->size != 0)
		element_swap(&stack_b->stack[0],&stack_b->stack[1]);
	ft_printf("ss\n");
}

void ra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_b;
	tmp = stack_a->stack[0];
	if (stack_a->size != 1 && stack_a->size != 0)
	{
		ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)*sizeof(t_element));
		stack_a->stack[stack_a->size - 1] = tmp;
	}
	ft_printf("ra\n");
}

void rb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_a;
	tmp = stack_b->stack[0];
	if (stack_b->size != 1 && stack_b->size != 0)
		ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[stack_b->size - 1] = tmp;
	ft_printf("rb\n");
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
	ft_printf("rr\n");
}

void rra_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_b;
	tmp = stack_a->stack[stack_a->size - 1];
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size - 1)*sizeof(t_element));
	stack_a->stack[0] = tmp;
	ft_printf("rra\n");
}

void rrb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;

	(void)stack_a;
	tmp = stack_b->stack[stack_b->size - 1];
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size - 1)*sizeof(t_element));
	stack_b->stack[0] = tmp;
	ft_printf("rrb\n");
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
	ft_printf("rrr\n");
}

void pb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;
	if (stack_a->size == 0)
	{
		ft_printf("pb\n");
		return;
	}
	tmp = stack_a->stack[0];
	ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)*sizeof(t_element));
	(stack_a->size)--;
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size)*sizeof(t_element));
	stack_b->stack[0] = tmp;
	stack_b->size++;
	ft_printf("pb\n");
}

void pa_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element tmp;
	if (stack_b->size == 0)
	{
		ft_printf("pa\n");
		return;
	}
	tmp = stack_b->stack[0];
	ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)*sizeof(t_element));
	(stack_b->size)--;
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size)*sizeof(t_element));
	stack_a->stack[0] = tmp;
	stack_a->size++;
	ft_printf("pa\n");
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