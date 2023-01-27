/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-number_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:05:24 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/27 19:38:19 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;	
}
static int duplicates_checker(int	*tab, int len)
{
	int i;
	int j;
	int dup;

	dup = 0;
	j = 0;
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
					return(0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
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
	if(!tab)
	{
		free_args(final);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (final[i])
	{
		tab[i] = ft_atoi_max(final[i], &check);
		if(!max_value_error(check))
		{
			free(tab);
			free_args(final);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	*len = i;
	if (!duplicates_checker(tab,*len))
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
		return(0);
	}
	if (check == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return(0);
	}
	return (1);
}

int	*tab_sort(int *tab, int len)
{
	int i;
	int check;

	check = -1;
	while (check != 1)
	{
		check = 1;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
			{	
				swap (&tab[i + 1], &tab[i]);
				check = -1;
			}	
			i++;
		}
	}
	
	return (0);
}

int *tab_copy(int *tab, int len)
{
	int *tab_dup;

	tab_dup = (int*)ft_calloc(len, sizeof(int));
	if(!tab_dup)
	{
		free(tab);
		exit(0);
	}
	ft_memcpy(tab_dup, tab, len*sizeof(int));
	return (tab_dup);
}
