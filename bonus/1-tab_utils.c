/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-number_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:48:34 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:06:29 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*tab_sort(int *tab, int len)
{
	int	i;
	int	check;

	check = -1;
	while (check != 1)
	{
		check = 1;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(&tab[i + 1], &tab[i]);
				check = -1;
			}
			i++;
		}
	}
	return (0);
}

int	*tab_copy(int *tab, int len)
{
	int	*tab_dup;

	tab_dup = (int *)ft_calloc(len, sizeof(int));
	if (!tab_dup)
	{
		free(tab);
		exit(0);
	}
	ft_memcpy(tab_dup, tab, len * sizeof(int));
	return (tab_dup);
}
