/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:36:36 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/16 12:03:47 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int	i;
	int	nbr = 5;
	ft_printf("%d", ft_atoi("-2147483649"));
}

struct stack_t
{
	int *data;
	int size;
}

t_list *arr = loadfromarguments();

t_stack a;
a.data = ft_calloc(ft_lstsize(arr));
a.size = 0;

int i = 0;
while (arr)
{
	a.data[i++] = (int)arr->content;
	a.size++;
	arr = arr->next;
}

// swap
int tmp = a.data[0];
a.data[0] = a.data[1];
a.data[1] = tmp;

// rotate
int tmp = a.data[0];
ft_memcpy(&a.data[1], &a.data[0], a.size - 1)
a.data[a.size] = tmp;



55 78 98 10 58
66 11 12 13 99 88 46
