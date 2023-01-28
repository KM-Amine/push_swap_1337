/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:43:40 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_stack *st)
{
	int	biggest;
	int	biggest_index;
	int	size;

	biggest = st->stack[0].nbr;
	biggest_index = 0;
	size = st->size - 1;
	while (size > 0)
	{
		if (st->stack[size].nbr > biggest)
		{
			biggest = st->stack[size].nbr;
			biggest_index = size;
		}
		size--;
	}
	return (biggest_index);
}

void	check_max_value(t_stack *sta, t_stack *stb, int i, int *biggest,
		int range)
{
	if (sta->stack[0].pos == *biggest - 1 && sta->stack[0].pos >= i + range)
	{
		move(rra, sta, stb);
		(*biggest)--;
	}
}

void	throw_down(t_stack *sta, t_stack *stb, int i, int *biggest, int max,
		int range)
{
	move(pb, sta, stb);
	if (sta->stack[0].pos >= i + 1 + range && sta->stack[0].pos != max - 1)
		move(rr, sta, stb);
	else
		move(rb, sta, stb);
	*biggest = max;
}

void	throw_up(t_stack *sta, t_stack *stb, int *biggest, int max)
{
	move(pb, sta, stb);
	if (stb->stack[0].pos < stb->stack[1].pos)
	{
		if (sta->stack[0].pos > sta->stack[1].pos && sta->stack[0].pos != max
			- 1)
			move(ss, sta, stb);
		else
			move(sb, sta, stb);
	}
	*biggest = max;
}

void	back_to_sta(t_stack *sta, t_stack *stb, int max)
{
	int	index;
	int	tmp;

	max--;
	while (max >= 0)
	{
		index = get_index(stb);
		tmp = stb->stack[index].pos;
		if (index <= (stb->size) / 2)
		{
			while (stb->stack[0].pos != tmp)
				move(rb, sta, stb);
			move(pa, sta, stb);
			max--;
		}
		else
		{
			while (stb->stack[0].pos != tmp)
				move(rrb, sta, stb);
			move(pa, sta, stb);
			max--;
		}
	}
}

void	send_to_stb(t_stack *sta, t_stack *stb, int len, int range)
{
	int	i;
	int	biggest;

	biggest = len;
	i = 0;
	while (i < len)
	{
		check_max_value(sta, stb, i, &biggest, range);
		if (sta->stack[0].pos < i)
		{
			throw_down(sta, stb, i, &biggest, len, range);
			i++;
		}
		else if (sta->stack[0].pos < i + range)
		{
			throw_up(sta, stb, &biggest, len);
			i++;
		}
		else
		{
			move(ra, sta, stb);
			continue ;
		}
	}
}
