/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-checking_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:14:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 17:19:54 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *sta)
{
	int	i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i + 1].pos)
			return (0);
		i++;
	}
	return (1);
}

int	sorted_check(t_stack *sta, t_stack *stb)
{
	if (sta->size == 1 && stb->size == 0)
		return (1);
	else if (is_sorted(sta) && stb->size == 0)
		return (1);
	return (-1);
}

void	cheking_system(t_stack *sta, t_stack *stb)
{
	char	*total;
	int		sorted;

	total = input_reader();
	instructions_executer(sta, stb, total);
	sorted = sorted_check(sta, stb);
	if (sorted == 1)
		ft_printf("OK\n");
	else if (sorted == -1)
		ft_printf("KO\n");
}
