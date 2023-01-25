/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-number_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:05:24 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/25 11:14:59 by mkhellou         ###   ########.fr       */
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
static void duplicates_checker(int	*tab, int len)
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
					ft_printf("Error");
					exit(0);	
				}
			}
			j++;
		}
		i++;
	}
	exit(0);

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
	duplicates_checker(tab,*len);
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
