/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:53:27 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/14 13:03:29 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	number_creator(const char *str, int i, int sign, int *check)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		if (sign > 0 && result > INT_MAX)
		{
			*check = 1;
			return (0);
		}
		if (sign < 0 && -result < INT_MIN)
		{
			*check = -1;
			return (-1);
		}
		i++;
	}
	return (sign * result);
}

int	ft_atoi_max(const char *str,int *check)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (number_creator(str, i, sign,check));
}
