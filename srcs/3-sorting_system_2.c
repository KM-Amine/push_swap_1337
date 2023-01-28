/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:27:55 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 13:19:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	smallest_first(t_stack *sta, t_stack *stb)
{
	if (sta->stack[1].nbr > sta->stack[2].nbr)
	{
		move(sa, sta, stb);
		move(ra, sta, stb);
	}
}

void	sorting_for_3(t_stack *sta, t_stack *stb)
{
	if (sta->stack[0].nbr > sta->stack[1].nbr
		&& sta->stack[0].nbr > sta->stack[2].nbr)
	{
		move(ra, sta, stb);
		if (sta->stack[0].nbr > sta->stack[1].nbr)
			move(sa, sta, stb);
	}
	else if (sta->stack[0].nbr > sta->stack[1].nbr
		&& sta->stack[0].nbr < sta->stack[2].nbr)
	{
		move(sa, sta, stb);
	}
	else if (sta->stack[0].nbr < sta->stack[1].nbr
		&& sta->stack[0].nbr > sta->stack[2].nbr)
	{
		move(rra, sta, stb);
	}
	else if (sta->stack[0].nbr < sta->stack[1].nbr
		&& sta->stack[0].nbr < sta->stack[2].nbr)
	{
		smallest_first(sta, stb);
	}
}

void	sorting_for_5(t_stack *sta, t_stack *stb)
{
	while (sta->stack[0].pos != 1 && sta->stack[0].pos != 0)
		move(ra, sta, stb);
	move(pb, sta, stb);
	while (sta->stack[0].pos != 1 && sta->stack[0].pos != 0)
		move(ra, sta, stb);
	move(pb, sta, stb);
	sorting_for_3(sta, stb);
	move(pa, sta, stb);
	move(pa, sta, stb);
	if (sta->stack[0].nbr > sta->stack[1].nbr)
		move(sa, sta, stb);
}

void	sorting_system(t_stack *sta, t_stack *stb)
{
	int	len;

	len = sta->size;
	if (len <= 3)
	{
		sorting_for_3(sta, stb);
	}
	else if (len <= 5)
	{
		sorting_for_5(sta, stb);
	}
	else if (len <= 100)
	{
		send_to_stb(sta, stb, len, 15);
		back_to_sta(sta, stb, len);
	}
	else
	{
		send_to_stb(sta, stb, len, 30);
		back_to_sta(sta, stb, len);
	}
}
