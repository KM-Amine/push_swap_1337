/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 18:01:45 by mkhellou         ###   ########.fr       */
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
	// int len;
	// int j;

	// len = sta->size;
	// j = 0;
	(void)stb;
	i = 0;
	while (i < sta->size)
	{
		ft_printf("%d-%d\n",get_index(i, sta), sta->stack[get_index(i, sta)].nbr);
		i++;
	}
	
	
	// while (j < len)
	// {
	// 	i = 0;
	// 	while (i < sta->size)
	// 	{
	// 		//ft_printf("%d-%d\n",j,sta->stack[i].pos);
	// 		if (sta->stack[0].pos != j)
	// 			move(ra, sta, stb);
	// 		i++;
	// 	}
	// 	move(pb, sta, stb);
	// 	j++;
	// }
	// j = 0;
	// while (j < len)
	// {
	//move(ra, sta, stb);
	//ft_printf("%d",sta->stack[0].nbr);
	// 	j++;
	// }
	
	// move(sa, sta, stb);
	// move(rra, sta, stb);
	// move(rra, sta, stb);
	return;
}
