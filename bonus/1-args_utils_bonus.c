/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-args_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:38:50 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 10:39:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	empty_string_checker(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_for_spaces_and_signes(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ')
				break ;
			j++;
			if (!argv[i][j])
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	free_total(char ***total)
{
	int	j;

	j = 1;
	while (total[j])
	{
		free(total[j]);
		j++;
	}
	free(total);
}

void	free_total_exit(char ***total)
{
	int	j;
	int	i;

	j = 1;
	while (total[j])
	{
		i = 0;
		while (total[j][i])
		{
			free(total[j][i]);
			i++;
		}
		free(total[j]);
		j++;
	}
	free(total);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
