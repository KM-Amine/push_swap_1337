/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/20 18:30:57 by mkhellou         ###   ########.fr       */
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

void check_max_value(t_stack *sta, t_stack *stb,int i,int *biggest, int range)
{
	if (sta->stack[0].pos == *biggest-1 && sta->stack[0].pos >= i + range)
	{
		move(rra,sta,stb);
		(*biggest)--;
	}
}

void throw_down(t_stack *sta, t_stack *stb,int i,int *biggest,int max,int range)
{
	move(pb, sta, stb);
	if(sta->stack[0].pos >= i + 1 + range)
		move(rr, sta, stb);
	else
		move(rb, sta, stb);
	*biggest = max;
}

void throw_up(t_stack *sta, t_stack *stb,int *biggest,int max)
{
	move(pb, sta, stb);
	if (stb->stack[0].pos < stb->stack[1].pos)
	{
		if (sta->stack[0].pos > sta->stack[1].pos )
			move(ss, sta, stb);
		else
			move(sb, sta, stb);
	}
	*biggest = max;
}

void back_to_sta(t_stack *sta, t_stack *stb,int max)
{
	int index;
	int tmp;

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

void send_to_stb(t_stack *sta, t_stack *stb, int len, int range)
{
	int i;
	int biggest;
	int max;

	
	max = len;
	biggest = len;
	i = 0;
	while (i < len)
	{
		check_max_value(sta,stb,i,&biggest,range);
		if (sta->stack[0].pos < i)
		{
			throw_down(sta,stb,i,&biggest,max,range);
			i++;
		}
		else if (sta->stack[0].pos < i + range)
		{
			throw_up(sta,stb,&biggest,max);
			i++;
		}
		else
		{
			move(ra, sta, stb);
			continue;
		}
	}
}

void sorting_for_3(t_stack *sta, t_stack *stb)
{
	if (sta->stack[0].nbr > sta->stack[1].nbr && sta->stack[0].nbr > sta->stack[2].nbr)
	{
		move(ra,sta,stb);
		if (sta->stack[0].nbr > sta->stack[1].nbr)
			move(sa,sta,stb);
	}
	else if (sta->stack[0].nbr > sta->stack[1].nbr && sta->stack[0].nbr < sta->stack[2].nbr)
	{
			move(sa,sta,stb);
	}
	else if (sta->stack[0].nbr < sta->stack[1].nbr && sta->stack[0].nbr > sta->stack[2].nbr)
	{
			move(rra,sta,stb);
	}
	else if (sta->stack[0].nbr < sta->stack[1].nbr && sta->stack[0].nbr < sta->stack[2].nbr)
	{
		if (sta->stack[1].nbr > sta->stack[2].nbr)
		{
			move(sa,sta,stb);
			move(ra,sta,stb);
		}
	}
}

void sorting_for_5(t_stack *sta, t_stack *stb)
{
	while (sta->stack[0].pos != 1 && sta->stack[0].pos != 0)
		move(ra,sta,stb);
	move(pb,sta,stb);
	while (sta->stack[0].pos != 1 && sta->stack[0].pos != 0)
		move(ra,sta,stb);
	move(pb,sta,stb);
	sorting_for_3(sta,stb);
	move(pa,sta,stb);
	move(pa,sta,stb);
	if(sta->stack[0].nbr > sta->stack[1].nbr)
		move(sa,sta,stb);
}

// pb pa rr ss segfault
// if already sorted
void sorting_system(t_stack *sta, t_stack *stb)
{
	int len;
	len = sta->size;
	
	if (len <=3)
	{
		sorting_for_3(sta,stb);
	}
	else if (len <= 5)
	{
		sorting_for_5(sta,stb);
	}
	else if (len <= 100)
	{	
		send_to_stb(sta,stb,len,15);
		back_to_sta(sta,stb,len);
	}
	else if (len <= 500)
	{
		send_to_stb(sta,stb,len,30);
		back_to_sta(sta,stb,len);
	}
}