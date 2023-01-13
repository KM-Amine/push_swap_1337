/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/13 19:04:01 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void exit_fuction(void)
{
	exit(EXIT_FAILURE);
}

char ***total_generator(int argc, char **argv)
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
					{
						ft_printf("Error: consecutive signes");
						exit_fuction();
					}
				}
				else if(argv[j][i] == ' ')
				{
					i++;
					continue;
				}
				else
				{
					ft_printf("Error: stranger character");
					exit_fuction();
				}
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

char **data_joiner(char*** total, int argc)
{
	int count;
	char **final;
	int i;
	int j;
	int c;
	
	count = total_counter(argc,total);
	final = (char **)ft_calloc(count +1, sizeof(char**));
	c = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (total[j][i])
		{
			final[c]=total[j][i];
			c++;
			i++;
		}
		j++;
	}
	return (final);
}
void free_total(char ***total,int argc)
{
	int j;

	j = 1;
	while (j < argc)
	{
		free(total[j]);
		j++;
	}
	free(total);
}

int	main(int argc, char **argv)
{
	char ***total;
	char **final;

	total = total_generator(argc, argv);
	final = data_joiner(total,argc);
	free_total(total,argc);
	int i = 0;
	check_duplicates(final);
	while (final[i])
	{
		ft_printf("%s\n", final[i]);
		i++;
	}
}
