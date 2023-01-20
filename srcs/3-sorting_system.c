/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/20 15:33:37 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_stack *st)
{
	int	biggest = st->stack[0].nbr;
	int	biggest_index = 0;
	int size = st->size;

	while (size > 0)
	{
		if (st->stack[size].nbr > biggest)
		{
			biggest = st->stack[size].nbr;
			biggest_index = size;
		}
		size--;
	}
	return(biggest_index);
}

void check_max_value(t_stack *sta, t_stack *stb,int i,int *biggest)
{
	if (sta->stack[0].pos == *biggest-1 && sta->stack[0].pos >= i + 30)
	{
		move(rra,sta,stb);
		(*biggest)--;
	}
}

void sorting_system(t_stack *sta, t_stack *stb)
{
	int i;
	int len;
	int max;
	int index;
	int tmp;
	int biggest;

	len = sta->size;
	max = len;
	biggest = max;
	i = 0;
	while (i < len)
	{
		// if (sta->stack[0].pos == biggest-1 && sta->stack[0].pos >= i + 30)
		// {
		// 	move(rra,sta,stb);
		// 	biggest--;
		// }
		check_max_value(sta,stb,i,&biggest);
		if (sta->stack[0].pos < i)
		{
			move(pb, sta, stb);
			if(sta->stack[0].pos >= i + 1 + 30)
				move(rr, sta, stb);
			else
				move(rb, sta, stb);
			i++;
			biggest = max;
		}
		else if (sta->stack[0].pos < i + 30)
		{
			move(pb, sta, stb);
			if (stb->stack[0].pos < stb->stack[1].pos)
			{
				if (sta->stack[0].pos > sta->stack[1].pos )
					move(ss, sta, stb);
				else
					move(sb, sta, stb);
			}
			biggest = max;
			i++;
		}
		else
		{
			move(ra, sta, stb);
			continue;
		}
	}
	max--;
	while (max >= 0)
	{
		index = get_index(stb);
		tmp = stb->stack[index].nbr;
		if (index < (stb->size)/2)
		{
			while (stb->stack[0].nbr != tmp )
				move(rb,sta,stb);	
			move(pa,sta,stb);
			max--;
		}
		else
		{
			while (stb->stack[0].nbr != tmp)
				move(rrb,sta,stb);	
			move(pa,sta,stb);
		 	max--;
		}
	}
}