/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/15 10:36:33 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_fuction(void)
{
	exit(EXIT_FAILURE);
}

//valgrind
//garbage collector system
int	main(int argc, char **argv)
{
	char	**args;
	int		*tab;
	int		i;
	int		len;

	args = argument_analyser(argc, argv);
	tab = numbers_converter(args, &len);
	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}
