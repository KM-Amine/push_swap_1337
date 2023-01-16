/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-errors_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:36:20 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 09:16:15 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	duplicate_analyser(char	**dup, char **final, int *i, int *j)
{
	(*j) = 0;
	while (dup[(*j)])
	{
		if (ft_strncmp(dup[(*j)], final[*i], ft_strlen(dup[(*j)])
				+ ft_strlen(final[*i])) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit_input_function();
		}
		(*j)++;
	}
}

char	**check_duplicates(char **final)
{
	int		count;
	char	**dup;
	int		i;
	int		j;

	count = 0;
	while (final[count])
		count++;
	dup = (char **)ft_calloc(count + 1, sizeof(char **));
	if(!dup)
		exit_null_free();
	dup[0] = final[0];
	i = 1;
	while (final[i])
	{
		duplicate_analyser(dup, final, &i, &j);
		dup[j] = final[i];
		i++;
	}
	free(final);
	return (dup);
}

void	sign_checker(char **argv, int i, int j)
{
	if (argv[j][i + 1] == '+' || argv[j][i + 1] == '-'
		|| argv[j][i + 1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit_input_function();
	}
	if (i != 0 && argv[j][i - 1] != ' ')
	{
		ft_putstr_fd("Error\n", 2);
		exit_input_function();
	}
}

void	error_detector(char **argv, int i, int j)
{
	i = 0;
	while (argv[j][i])
	{
		if (!ft_isdigit(argv[j][i]))
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				sign_checker(argv, i, j);
			}
			else if (argv[j][i] == ' ')
			{
				i++;
				continue ;
			}
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit_input_function();
			}
		}
		i++;
	}
}

