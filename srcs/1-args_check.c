/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-args_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:25:30 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/25 13:52:56 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void empty_string_checker(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{	
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		i++;
	}	
}

char	**argument_analyser(int argc, char **argv)
{
	char	***total;
	char	**final;

	if (argc == 1)
		exit(EXIT_FAILURE);
	empty_string_checker(argc,argv);
	total = total_generator(argc, argv);
	final = data_joiner(total, argc);
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
		exit_null_free();
	j = 1;
	while (j < argc)
	{
		i = 0;
		error_detector(argv, i, j);
		total[j] = ft_split(argv[j], ' ');
		if(!total[j])
		{
			free_total_exit(total);
			exit_null_free();
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
	{
		exit_null_free();
	}
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
	int i;

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
	int i;

	i =0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}