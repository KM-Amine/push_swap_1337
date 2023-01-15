/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:05:24 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/15 09:44:47 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_value_error(int check)
{
	if (check == 1)
	{
		ft_putstr_fd("Error", 2);
		exit_fuction();
	}
	if (check == -1)
	{
		ft_putstr_fd("Error", 2);
		exit_fuction();
	}
}

int	*numbers_converter(char **final, int *len)
{
	int	i;
	int	*tab;
	int	check;

	check = 0;
	i = 0;
	while (final[i])
		i++;
	tab = (int *)ft_calloc(i, sizeof(int));
	i = 0;
	while (final[i])
	{
		tab[i] = ft_atoi_max(final[i], &check);
		max_value_error(check);
		i++;
	}
	*len = i;
	return (tab);
}
