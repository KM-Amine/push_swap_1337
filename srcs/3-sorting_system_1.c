/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 13:22:04 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_max_value(t_pstacks pstacks, int i, int *biggest, t_len_data data)
{
	if (pstacks.sta->stack[0].pos == *biggest - 1
		&& pstacks.sta->stack[0].pos >= i + data.range)
	{
		move(rra, pstacks.sta, pstacks.stb);
		(*biggest)--;
	}
}

void	throw_down(t_pstacks pstacks, int i, int *biggest, t_len_data data)
{
	move(pb, pstacks.sta, pstacks.stb);
	if (pstacks.sta->stack[0].pos >= i + 1 + data.range
		&& pstacks.sta->stack[0].pos != data.max - 1)
		move(rr, pstacks.sta, pstacks.stb);
	else
		move(rb, pstacks.sta, pstacks.stb);
	*biggest = data.max;
}

void	throw_up(t_pstacks pstacks, int *biggest, t_len_data data)
{
	move(pb, pstacks.sta, pstacks.stb);
	if (pstacks.stb->stack[0].pos < pstacks.stb->stack[1].pos)
	{
		if (pstacks.sta->stack[0].pos > pstacks.sta->stack[1].pos
			&& pstacks.sta->stack[0].pos != data.max - 1)
			move(ss, pstacks.sta, pstacks.stb);
		else
			move(sb, pstacks.sta, pstacks.stb);
	}
	*biggest = data.max;
}
