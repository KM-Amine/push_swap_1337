/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 18:10:23 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(int p, t_stack *sta)
{
	int i;

	i = 0;
	while (sta->stack[i].pos != p)
		i++;
	return(i);
}

void	sorting_system(t_stack *sta, t_stack *stb)
{
	int i;
	int len;
	int j;

	len = sta->size;
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < sta->size)
		{
			if (sta->stack[0].pos != j)
				move(ra, sta, stb);
			i++;
		}
		move(pb, sta, stb);
		j++;
	}
	j = 0;
	while (j < len)
	{
		move(pa, sta, stb);
		j++;
	}
	return;
}
