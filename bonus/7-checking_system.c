/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-checking_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:14:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/28 16:53:56 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *sta)
{
	int	i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i + 1].pos)
			return (0);
		i++;
	}
	return (1);
}

int	sorted_check(t_stack *sta, t_stack *stb)
{
	if (sta->size == 1 && stb->size == 0)
		return (1);
	else if (is_sorted(sta) && stb->size == 0)
		return (1);
	return (-1);
}

char	*ft_strfjoin(char *s1, char *s2)
{
	int		len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (result);
}

char	*input_reader(void)
{
	char	*str;
	char	*total;

	str = get_next_line(0);
	total = (char *)ft_calloc(1, 1);
	while (str)
	{
		if (ft_strlen(str) != 4 && ft_strlen(str) != 3)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (!ft_strncmp(str, "sa\n", 3) || !ft_strncmp(str, "sb\n", 3))
			total = ft_strfjoin(total, str);
		else if (!ft_strncmp(str, "ss\n", 3) || !ft_strncmp(str, "pa\n", 3))
			total = ft_strfjoin(total, str);
		else if (!ft_strncmp(str, "pb\n", 3) || !ft_strncmp(str, "ra\n", 3))
			total = ft_strfjoin(total, str);
		else if (!ft_strncmp(str, "rb\n", 3) || !ft_strncmp(str, "rr\n", 3))
			total = ft_strfjoin(total, str);
		else if (!ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "rrb\n", 4))
			total = ft_strfjoin(total, str);
		else if (!ft_strncmp(str, "rrr\n", 4))
			total = ft_strfjoin(total, str);
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		str = get_next_line(0);
	}
	return (total);
}

void	instruction_conditions(t_stack *sta, t_stack *stb, char	**act, int i)
{
	if (ft_strncmp(act[i], "sa", 3) == 0)
		move(sa, sta, stb);
	else if (ft_strncmp(act[i], "sb", 3) == 0)
		move(sb, sta, stb);
	else if (ft_strncmp(act[i], "ss", 3) == 0)
		move(ss, sta, stb);
	else if (ft_strncmp(act[i], "pa", 3) == 0)
		move(pa, sta, stb);
	else if (ft_strncmp(act[i], "pb", 3) == 0)
		move(pb, sta, stb);
	else if (ft_strncmp(act[i], "ra", 3) == 0)
		move(ra, sta, stb);
	else if (ft_strncmp(act[i], "rb", 3) == 0)
		move(rb, sta, stb);
	else if (ft_strncmp(act[i], "rr", 3) == 0)
		move(rr, sta, stb);
	else if (ft_strncmp(act[i], "rra", 4) == 0)
		move(rra, sta, stb);
	else if (ft_strncmp(act[i], "rrb", 4) == 0)
		move(rrb, sta, stb);
	else if (ft_strncmp(act[i], "rrr", 4) == 0)
		move(rrr, sta, stb);
}

void	instructions_executer(t_stack *sta, t_stack *stb, char *total)
{
	int		i;
	char	**actions;

	actions = ft_split(total, '\n');
	free(total);
	i = 0;
	while (actions[i])
	{
		instruction_conditions(sta, stb, actions, i);
		i++;
	}
	free_args(actions);
}

void	cheking_system(t_stack *sta, t_stack *stb)
{
	char	*total;
	int		sorted;

	total = input_reader();
	instructions_executer(sta, stb, total);
	sorted = sorted_check(sta, stb);
	if (sorted == 1)
		ft_printf("OK\n");
	else if (sorted == -1)
		ft_printf("KO\n");
}
