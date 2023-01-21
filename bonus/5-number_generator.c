/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-number_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:45:14 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 09:45:17 by mkhellou         ###   ########.fr       */
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
		exit_null_free();
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

void	max_value_error(int check)
{
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit_input_function();
	}
	if (check == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit_input_function();
	}
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
	ft_memcpy(tab_dup, tab, len*sizeof(int));
	return (tab_dup);
}