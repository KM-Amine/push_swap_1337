/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:18:36 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 13:22:11 by mkhellou         ###   ########.fr       */
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

void	to_stb_operations(t_pstacks	pstacks, t_len_data	data, int *biggest)
{
	int	i;

	i = 0;
	while (i < data.max)
	{
		check_max_value(pstacks, i, biggest, data);
		if (pstacks.sta->stack[0].pos < i)
		{
			throw_down(pstacks, i, biggest, data);
			i++;
		}
		else if (pstacks.sta->stack[0].pos < i + data.range)
		{
			throw_up(pstacks, biggest, data);
			i++;
		}
		else
		{
			move(ra, pstacks.sta, pstacks.stb);
			continue ;
		}
	}
}

void	send_to_stb(t_stack *sta, t_stack *stb, int len, int range)
{
	int			biggest;
	t_pstacks	pstacks;
	t_len_data	data;

	data.max = len;
	data.range = range;
	pstacks.sta = sta;
	pstacks.stb = stb;
	biggest = len;
	to_stb_operations(pstacks, data, &biggest);
}
