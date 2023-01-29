/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-number_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:05:24 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 12:05:37 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	duplicates_checker(int *tab, int len)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	while (i < len)
	{
		dup = 0;
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab[j])
			{
				dup++;
				if (dup >= 2)
				{
					ft_putstr_fd("Error\n", 2);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	number_creator(int *tab, char **final, int i, int *check)
{
	tab[i] = ft_atoi_max(final[i], check);
	if (!max_value_error(*check))
	{
		free(tab);
		free_args(final);
		exit(EXIT_FAILURE);
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
	if (!tab)
	{
		free_args(final);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (final[++i])
		number_creator(tab, final, i, &check);
	*len = i;
	if (!duplicates_checker(tab, *len))
	{
		free(tab);
		free_args(final);
		exit(EXIT_FAILURE);
	}
	return (tab);
}

int	max_value_error(int check)
{
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
