/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-errors_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:36:20 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 11:44:26 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	duplicate_analyser(char **dup, char **final, int *i, int *j)
{
	(*j) = 0;
	while (dup[(*j)])
	{
		if (ft_strncmp(dup[(*j)], final[*i], ft_strlen(dup[(*j)])
				+ ft_strlen(final[*i])) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		(*j)++;
	}
	return (1);
}

void	string_duplicate(char **dup, char **final, int *i, int *j)
{
	if (!duplicate_analyser(dup, final, i, j))
	{
		free_args(final);
		free(dup);
		exit(EXIT_FAILURE);
	}
	dup[*j] = final[*i];
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
	if (!dup)
	{
		free_args(final);
		exit(EXIT_FAILURE);
	}
	dup[0] = final[0];
	i = 1;
	while (final[i])
	{
		string_duplicate(dup, final, &i, &j);
		i++;
	}
	free(final);
	return (dup);
}

int	sign_checker(char **argv, int i, int j)
{
	if (argv[j][i + 1] == '+' || argv[j][i + 1] == '-' || argv[j][i
		+ 1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (i != 0 && argv[j][i - 1] != ' ')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	error_detector(char **argv, int i, int j)
{
	i = 0;
	while (argv[j][i])
	{
		if (!ft_isdigit(argv[j][i]))
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				if (!sign_checker(argv, i, j))
					return (0);
			}
			else if (argv[j][i] == ' ')
			{
				i++;
				continue ;
			}
			else
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
