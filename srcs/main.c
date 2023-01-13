/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/13 18:29:25 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


char **total_generator(int argc, char **argv)
{
	char ***total;
	int i;
	int j;

	total= (char***)ft_calloc(argc +1, sizeof(char**)); 
	j = 1;
	while (j < argc)
	{
		i = 0;
		while(argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
			{
				if(argv[j][i] == '+' || argv[j][i] == '-')
				{
					if (argv[j][i+1] == '+' || argv[j][i+1] == '-' || argv[j][i+1] == '\0')
						exit(EXIT_FAILURE);
				}
				else if(argv[j][i] == ' ')
				{
					i++;
					continue;
				}
				else
					exit(EXIT_FAILURE);
			}
			i++;
		}
		total[j] = ft_split(argv[j], ' ');
		j++;
	}
	return (total);
}

int total_counter(int argc,char ***total)
{
	int i;
	int j;
	int count;

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
	return(count);
}

int	main(int argc, char **argv)
{

	ft_printf("--%d--\n", total_counter(argc,total));
}
