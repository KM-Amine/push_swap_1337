/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/19 12:43:16 by mkhellou         ###   ########.fr       */
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

// void	sorting_system(t_stack *sta, t_stack *stb)
// {
// 	int i;
// 	int len;
// 	int j;

// 	len = sta->size;
// 	j = 0;
// 	while (j < len)
// 	{
// 		i = 0;
// 		while (i < sta->size)
// 		{
// 			if (sta->stack[0].pos != j)
// 				move(ra, sta, stb);
// 			i++;
// 		}
// 		move(pb, sta, stb);
// 		j++;
// 	}
// 	j = 0;
// 	while (j < len)
// 	{
// 		move(pa, sta, stb);
// 		j++;
// 	}
// 	return;
// }

void sorting_system(t_stack *sta, t_stack *stb)
{
	int i;
	int len;
//	int pos;
	int max;
	(void)stb;
//	move(pb,sta,stb);
	len = sta->size;
	max = len;
	i = 0;
	while (i < len)
	{
		if (sta->stack[0].pos < i)
		{
			move(pb, sta, stb);
			move(rb, sta, stb);
			i++;
		}
		else if (sta->stack[0].pos < i + 30)
		{
		//	ft_printf("%d---",i);
			move(pb, sta, stb);
			i++;
		}
		else
		{
			move(ra, sta, stb);
			continue;
		}
	}
	//move(pa,sta,stb);
	// len--;
	// while (len >= 0)
	// {
	// 	// pos = get_index(len,sta);
	// 	// // ft_printf("%d-",pos);
	// 	// len--;
	// 	// if (pos > (stb->size)/2)
	// 	// {
	// 	while (sta->stack[0].pos != len)
	// 	{
	// 		move(ra,sta,stb);	
	// 	}
	// 	//	ft_printf("%d %d",sta->stack[0].pos, len);
	// 	move(pb,sta,stb);
	// 	len--;
	// 		//move(pa,sta,stb);
	// 	// 	len--;
	// 	// }
	// 	// else
	// 	// {
	// 	// 	while (stb->stack[0].nbr != len)
	// 	// 		move(rb,sta,stb);	
	// 	// 	//move(pa,sta,stb);
	// 	// 	len--;
	// 	// }
	// }
	max--;
	while (max >= 0)
	{
		int index = get_index(stb);
		int tmp = stb->stack[index].nbr;
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
			// while (stb->stack[0].pos != max)
			// 	move(rrb,sta,stb);	
			// move(pa,sta,stb);
		 	// max--;
	}
}