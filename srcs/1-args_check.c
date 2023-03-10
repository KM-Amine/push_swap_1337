/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-args_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:25:30 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 10:40:36 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**argument_analyser(int argc, char **argv)
{
	char	***total;
	char	**final;

	if (argc <= 1)
		exit(0);
	empty_string_checker(argc, argv);
	check_for_spaces_and_signes(argc, argv);
	total = total_generator(argc, argv);
	final = data_joiner(total, argc);
	if (final == NULL)
	{
		free_total_exit(total);
		exit(EXIT_FAILURE);
	}
	free_total(total);
	final = check_duplicates(final);
	return (final);
}

char	***total_generator(int argc, char **argv)
{
	char	***total;
	int		i;
	int		j;

	total = (char ***)ft_calloc(argc + 1, sizeof(char **));
	if (!total)
		exit(EXIT_FAILURE);
	j = 1;
	while (j < argc)
	{
		i = 0;
		if (!error_detector(argv, i, j))
		{
			free_total_exit(total);
			exit(EXIT_FAILURE);
		}
		total[j] = ft_split(argv[j], ' ');
		if (!total[j])
		{
			free_total_exit(total);
			exit(EXIT_FAILURE);
		}
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
	if (!final)
		return (NULL);
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
