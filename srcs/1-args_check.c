/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:25:30 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/15 09:20:34 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**argument_analyser(int argc, char **argv)
{
	char	***total;
	char	**final;

	if (argc == 1)
		exit(EXIT_FAILURE);
	total = total_generator(argc, argv);
	final = data_joiner(total, argc);
	free_total(total, argc);
	final = check_duplicates(final);
	return (final);
}

void	free_total(char ***total, int argc)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		free(total[j]);
		j++;
	}
	free(total);
}

char	***total_generator(int argc, char **argv)
{
	char	***total;
	int		i;
	int		j;

	total = (char ***)ft_calloc(argc + 1, sizeof(char **));
	j = 1;
	while (j < argc)
	{
		i = 0;
		error_detector(argv, i, j);
		total[j] = ft_split(argv[j], ' ');
		j++;
	}
	return (total);
}

int	total_counter(int argc, char ***total)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (total[j][i])
		{
			count++;
			i++;
		}
		j++;
	}
	return (count);
}

char	**data_joiner(char ***total, int argc)
{
	int		count;
	char	**final;
	int		i;
	int		j;
	int		c;

	count = total_counter(argc, total);
	final = (char **)ft_calloc(count + 1, sizeof(char **));
	c = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (total[j][i])
		{
			final[c] = total[j][i];
			c++;
			i++;
		}
		j++;
	}
	return (final);
}
