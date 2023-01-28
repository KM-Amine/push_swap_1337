/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stack_operations_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:20:54 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:25:21 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	if (stack_a->size == 0)
	{
		ft_printf("pb\n");
		return ;
	}
	tmp = stack_a->stack[0];
	ft_memmove(&(stack_a->stack[0]), &(stack_a->stack[1]), (stack_a->size - 1)
		* sizeof(t_element));
	(stack_a->size)--;
	ft_memmove(&(stack_b->stack[1]), &(stack_b->stack[0]), (stack_b->size)
		* sizeof(t_element));
	stack_b->stack[0] = tmp;
	stack_b->size++;
	ft_printf("pb\n");
}

void	pa_move(t_stack *stack_a, t_stack *stack_b)
{
	t_element	tmp;

	if (stack_b->size == 0)
	{
		ft_printf("pa\n");
		return ;
	}
	tmp = stack_b->stack[0];
	ft_memmove(&(stack_b->stack[0]), &(stack_b->stack[1]), (stack_b->size - 1)
		* sizeof(t_element));
	(stack_b->size)--;
	ft_memmove(&(stack_a->stack[1]), &(stack_a->stack[0]), (stack_a->size)
		* sizeof(t_element));
	stack_a->stack[0] = tmp;
	stack_a->size++;
	ft_printf("pa\n");
}

void	move(int nbr, t_stack *stack_a, t_stack *stack_b)
{
	void	(*action[11])(t_stack *, t_stack *);

	action[sa] = sa_move;
	action[sb] = sb_move;
	action[ss] = ss_move;
	action[pa] = pa_move;
	action[pb] = pb_move;
	action[ra] = ra_move;
	action[rb] = rb_move;
	action[rr] = rr_move;
	action[rra] = rra_move;
	action[rrb] = rrb_move;
	action[rrr] = rrr_move;
	(*action[nbr])(stack_a, stack_b);
}
