/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-checking_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:14:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 18:33:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//segfault shit

int is_sorted(t_stack *sta)
{
	int i;

	i = 0;
	while (i < sta->size - 1)
	{
		if (sta->stack[i].pos > sta->stack[i+1].pos)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int sorted_check(t_stack *sta)
{
	if (sta->size == 1)
		return(1);
	if (is_sorted(sta))
		return(1);
	return(-1);
}

void cheking_system(t_stack *sta, t_stack *stb)
{
	char *str;
	char *all;
	char **instruct;
	(void)sta;
	(void)stb;

	all = "";
	while (1)
	{
		str =get_next_line(0);
		if (!str)
			break;
		if (ft_strlen(str) != 4 && ft_strlen(str) != 3)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (ft_strncmp(str,"sa\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"sb\n",5) == 0)
			all =ft_strjoin(all,str);	
		else if (ft_strncmp(str,"ss\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"pa\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"pb\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"ra\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rb\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rr\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rra\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rrb\n",5) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rrr\n",5) == 0)
			all =ft_strjoin(all,str);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	instruct = ft_split(all,'\n');
	int i;
	i = 0;
	while (instruct[i])
	{
		str = instruct[i];
		if (ft_strncmp(str,"sa",5) == 0)
			move(sa,sta,stb);
		else if (ft_strncmp(str,"sb",5) == 0)
			move(sb,sta,stb);	
		else if (ft_strncmp(str,"ss",5) == 0)
			move(ss,sta,stb);
		else if (ft_strncmp(str,"pa",5) == 0)
			move(pa,sta,stb);
		else if (ft_strncmp(str,"pb",5) == 0)
			move(pb,sta,stb);
		else if (ft_strncmp(str,"ra",5) == 0)
			move(ra,sta,stb);
		else if (ft_strncmp(str,"rb",5) == 0)
			move(rb,sta,stb);
		else if (ft_strncmp(str,"rr",5) == 0)
			move(rr,sta,stb);
		else if (ft_strncmp(str,"rra",5) == 0)
			move(rra,sta,stb);
		else if (ft_strncmp(str,"rrb",5) == 0)
			move(rrb,sta,stb);
		else if (ft_strncmp(str,"rrr",5) == 0)
			move(rrr,sta,stb);
		i++;
	}
	int sorted;
	sorted = sorted_check(sta);
	if (sorted == 1)
		ft_printf("OK\n");
	else if (sorted == -1)
		ft_printf("KO\n");
}