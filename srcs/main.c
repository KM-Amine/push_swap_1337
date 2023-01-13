/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/13 19:27:29 by mkhellou         ###   ########.fr       */
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

char **check_duplicates(char **final)
{
	int count;
	char **dup;
	int i;
	int j;

	count = 0;
	while (final[count])
		count++;
	dup = (char **)ft_calloc(count +1, sizeof(char**));
	
	dup[0] = final[0];
	i = 1;
	while (final[i])
	{
		j = 0;
		while (dup[j])
		{
			if (ft_strncmp(dup[j],final[i],ft_strlen(dup[j])+ft_strlen(final[i])) == 0)
			{
				ft_printf("Eroor: their is duplicates in numbers\n");
				exit_fuction();
			}
			j++;
		}
		dup[j] = final[i];
		i++;
	}
	free(final);
	return (dup);
}

int **numbers_converter(char **final)
{
	int i;
	int *tab;

	i = 0;
	while (final[i])
		i++;
	tab= (int)ft_calloc();	
}

int	main(int argc, char **argv)
{
	char ***total;
	char **final;
	int **tab;

	total = total_generator(argc, argv);
	final = data_joiner(total,argc);
	free_total(total,argc);
	int i = 0;
	final = check_duplicates(final);
	tab = numbers_converter(final);
	while (final[i])
	{
		ft_printf("%s\n", final[i]);
		i++;
	}
}
